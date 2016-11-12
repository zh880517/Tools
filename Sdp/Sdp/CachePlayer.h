#ifndef _SDP_CACHEROLE_HPP_
#define _SDP_CACHEROLE_HPP_

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <Name.h>

template<Key, Value>
Value* FindMapPtr(std::map<Key, Value>& mMap, Key key)
{
	auto it = mMap.find(key);
	if (it != mMap.end())
	{
		return &(it->second);
	}
	return nullptr;
}

template<Key, Value>
const Value* FindMapPtr(const std::map<Key, Value>& mMap, Key key)
{
	auto it = mMap.find(key);
	if (it != mMap.cend())
	{
		return &(it->second);
	}
	return nullptr;
}

class Player_BaseData
{
public:
	Player_BaseData() 
		:CreatTime(0), Level(1), BuySpace(0)//这里使用data里面的默认值，如果有的话，数值类型是0，字符串是空，bool是false
	{}
	uint32_t	GetCreatTime()const { return CreatTime; }
	uint32_t	GetLevel()const { return Level; }
	uint32_t	GetBuySpace()const { return BuySpace; }

	template<T>
	bool		SetLevel(T &t, uint32_t iLevel) 
	{
		if (iLevel == Level) return false; 
		Level = iLevel;
		t.Update(Name("player.base"), Name("Level"), Level);//Update里面会写redis和发布消息
		return true;
	}

	template<T>
	void		visit(T& t)
	{
		t.Property(Name("player.base"), Name("CreatTime"), CreatTime, false); //最后一个参数是是否拥有修改权 Name会在生成代码的时候直接计算hash值
		t.Property(Name("player.base"), Name("Level"), Level, true);
		t.Property(Name("player.bag"), Name("BuySpace"), BuySpace, false);
	}

private:
	uint32_t	CreatTime;
	uint32_t	Level;
	uint32_t	BuySpace;
};

class Player_ItemBagData
{
public:
	uint32_t GetBaseID()const { return BaseID; }
	uint32_t GetItemNum()const { return ItemNum; }

	template<T>
	bool	SetBaseID(T &t, uint32_t iBaseID)
	{
		if (iBaseID == BaseID) return false;
		return t.Update(Name("player.bag.item"), Name("BaseID"), BaseID);
	}

	template<T>
	bool	SetItemNum(T &t, uint32_t iItemNum)
	{
		if (iItemNum == ItemNum) return false;
		t.Update(Name("player.bag.item"), Name("ItemNum"), ItemNum);
		return true;
	}

	template<T>
	void	visit(T& t)
	{
		t.Property(Name("player.bag.item"), Name("BaseID"), BaseID, true);
		t.Property(Name("player.bag.item"), Name("ItemNum"), ItemNum, true);
	}
private:
	uint32_t BaseID;
	uint32_t ItemNum;
};
class PlayerData
{
public:
	Player_BaseData& GetPlayerBase() { return stPlayerBase; }
	Player_ItemBagData* GetItemBagData(uint64_t iIndex) { return FindMapPtr(mItemBag, iIndex); }

	//拥有对ower权限的才有del和add操作接口
	template<T>
	bool	AddItemBagData(T& t, const Player_ItemBagData& stData, uint64_t iIndex)
	{
		if (FindMapPtr(mItemBag, iIndex) == nullptr) return false;
		mItemBag[iIndex] = stData;
		t.Add(iIndex);
		stData.visit(t);
		t.done();
		return true;
	}
	template<T>
	bool	DeleItemBagData(T& t, uint64_t iIndex)
	{
		auto it = mItemBag.find(iIndex);
		if (it != mItemBag.end())
		{
			t.Delete(iIndex);
			it->second.visit(t);
			mItemBag.erase(it);
			t.done();
			return true;
		}
		return false;
	}
	//对外部提供的遍历接口，穿进去的仿函数、std::function、 匿名函数，返回值为bool类型，返回false代表结束循环，一般用匿名函数比较方便
	template <T>
	void	ForEacheItemBagData(T&t)
	{
		for (auto it : mItemBag)
		{
			if (!t(it->first, it->second))
				return;
		}
	}

	template<T>
	void visit(T& t)
	{
		t.Struct(Name("PlayerBase"), stPlayerBase);
		t.Repeat(Name("palyer.bag.item"), mItemBag);
	}
private:
	Player_BaseData stPlayerBase;
	std::map<uint64_t, Player_ItemBagData> mItemBag;
};

class Scene_Player_ItemBagData
{
public:
	uint32_t	GetBaseID()const { return BaseID; }
	uint32_t	GetItemNum()const { return ItemNum; }

	template<T>
	void visit(T& t)
	{
		t.Property(Name("player.bag.item"), Name("BaseID"), BaseID, false);
		t.Property(Name("player.bag.item"), Name("ItemNum"), ItemNum, false);
	}
private:
	uint32_t	BaseID;
	uint32_t	ItemNum;
};
class Scene_PlayerData
{
public:
	uint32_t	GetLevel()const { return Level; }
	Scene_Player_ItemBagData* GetItemBagData(uint32_t iIndex) { return FindMapPtr(mItemBag, iIndex); }

	template<T>
	void	visit(T& t)
	{
		t.Property(Name("player.base"), Name("Level"), Level, false);
		t.Repeat(Name("player.bag.item"), mItemBag);
	}

	template <T>
	void	ForEacheItemBagData(T& t)
	{
		for (auto it : mItemBag)
		{
			if (!t(it->first, it->second))
				return;
		}
	}
private:
	uint32_t Level;
	std::map<uint64_t, Scene_Player_ItemBagData> mItemBag;
};
class SceneData
{
public:
	Scene_PlayerData* GetPlayer(uint64_t iIndex) { return FindMapPtr(mPlayer, iIndex); }

	//map类型的元素删除需要移除相关的订阅，不涉及redis数据的删除
	template<T>
	bool	DelePlayer(T&t, uint64_t iIndex)
	{
		auto it = mPlayer.find(iIndex);
		if (it != mPlayer.end())
		{
			t.Remove(iIndex);
			it->second.visit(t);
			mPlayer.erase(it);
			return true;
		}
		return false;
	}

	template<T>
	Scene_PlayerData* AddPlayer(T& t, uint64_t iIndex)
	{
		Scene_PlayerData& stData = mPlayer[iIndex];
		t.Load(iIndex);
		stData.visit(t);
		t.Done();
		return &stData;
	}

	template<T>
	void visit(T& t)
	{
		t.Map(Name("Player"), mPlayer);
	}

	template <T>
	void	ForEachePlayerData(T& t)
	{
		for (auto it : mItemBag)
		{
			if (!t(it->first, it->second))
				return;
		}
	}
private:
	std::map<uint64_t, Scene_PlayerData> mPlayer;
};

#endif
