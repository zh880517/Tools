#include "CachePlayer.h"

namespace Cache
{
	PlayerBase::PlayerBase(uint64_t iID, const std::string& strName, uint32_t iCareer, uint32_t iLevel, uint32_t iExp, uint64_t iFamilyID, uint32_t dtCreatTime)
		:ID(iID), Name(strName), Career(iCareer), Level(iLevel), Exp(iExp), FamilyID(iFamilyID), CreatTime(dtCreatTime)
	{}
	
	void PlayerBase::Init(Actor* pActor, uint64_t iID, const std::string & strName, uint32_t iCareer, uint32_t iLevel, uint32_t iExp, uint64_t iFamilyID, uint32_t dtCreatTime)
	{
		ID = iID;
		Name = strName;
		Career = iCareer;
		Level = iLevel;
		Exp = iExp;
		FamilyID = iFamilyID;
		CreatTime = dtCreatTime;
		if (pActor)
		{
			//pActor->CreatRedisHash("PlayerBase", ID, field ,value ...);
		}
	}

	bool PlayerBase::SetName(Actor* pActor, const std::string & strName)
	{
		if (strName == Name) return false;
		Name = strName;
		//assert(pActor)
		//pActor->SetRedisHash("PlayerBase", ID, "Name", Name)
		//每个进程做一个全局唯一的Redis管理器，可以用一个统一的接口来处理
		//或者每个Set接口添加一个Actor指针，Actor里面添加Redis的处理接口，这样每个Actor在处理的时候缓存起来所有的操作，防止重复，
		//等Actor处理完所有的当前消息后，调用对应的redis处理接口处理，这样减少了重复的数据保存操作和redis管理器的锁的密度
		return true;
	}
	bool PlayerBase::SetCareer(Actor* pActor, uint32_t iCareer)
	{
		if (iCareer == Career) return false;
		Career = iCareer;
		//SetRedisHash("PlayerBase", ID, "Career", Career)
	}
	bool PlayerBase::SetLevel(Actor* pActor, uint32_t iLevel)
	{
		if (iLevel == Level) return false;
		Level = iLevel;
		//assert(pActor)
		//pActor->SetRedisHash("PlayerBase", ID, "Level", Level)
		return true;
	}
	bool PlayerBase::SetExp(Actor* pActor, uint32_t iExp)
	{
		if (iExp == Exp) return false;
		Exp = iExp;
		//assert(pActor)
		//pActor->SetRedisHash("PlayerBase", ID, "Exp", Exp)
		return true;
	}
	bool PlayerBase::SetFamilyID(Actor* pActor, uint64_t iFamilyID)
	{
		if (iFamilyID == FamilyID) return false;
		FamilyID = iFamilyID;
		//assert(pActor)
		//pActor->SetRedisHash("PlayerBase", ID, "FamilyID", FamilyID)
		return true;
	}
	bool PlayerBase::SetCreatTime(Actor* pActor, uint32_t dtCreatTimes)
	{
		if (dtCreatTimes == CreatTime) return false;
		CreatTime = dtCreatTimes;
		//assert(pActor)
		//pActor->SetRedisHash("PlayerBase", ID, "CreatTime", CreatTime)
		return true;
	}
}