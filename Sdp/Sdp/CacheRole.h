#ifndef _SDP_CACHEROLE_HPP_
#define _SDP_CACHEROLE_HPP_

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Sdp.h"
using namespace std;

namespace EELCache
{
struct CacheIDNum
{
	uint32_t iID;
	uint32_t iNum;

	CacheIDNum(): 
		iID(0), 
		iNum(0)
	{
	}
	const char *getName() const { return "CacheIDNum"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iID != 0) t.visit(0, false, "iID", iID);
			if (iNum != 0) t.visit(1, false, "iNum", iNum);
		}
		else
		{
			t.visit(0, false, "iID", iID);
			t.visit(1, false, "iNum", iNum);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iID != 0) t.visit(0, false, "iID", iID);
			if (iNum != 0) t.visit(1, false, "iNum", iNum);
		}
		else
		{
			t.visit(0, false, "iID", iID);
			t.visit(1, false, "iNum", iNum);
		}
	}
	void swap(CacheIDNum &b)
	{
		using std::swap;
		swap(iID, b.iID);
		swap(iNum, b.iNum);
	}
	bool operator== (const CacheIDNum &rhs) const
	{
		return iID == rhs.iID
			&& iNum == rhs.iNum;
	}
	bool operator!= (const CacheIDNum &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheRoleBase
{
	uint32_t iRegTime;
	uint32_t iLastLoginTime;
	uint32_t iThisLoginTime;
	uint32_t iOnlineTotalTime;
	uint32_t iTotalLoginTimes;
	uint32_t iTotalLoginDays;
	uint32_t iContinuousLoginDays;
	uint32_t iLogoutTime;
	uint32_t iTotalCoin;
	uint32_t iTotalRedDiamond;
	uint32_t iTotalBlueDiamond;

	CacheRoleBase(): 
		iRegTime(0), 
		iLastLoginTime(0), 
		iThisLoginTime(0), 
		iOnlineTotalTime(0), 
		iTotalLoginTimes(0), 
		iTotalLoginDays(0), 
		iContinuousLoginDays(0), 
		iLogoutTime(0), 
		iTotalCoin(0), 
		iTotalRedDiamond(0), 
		iTotalBlueDiamond(0)
	{
	}
	const char *getName() const { return "CacheRoleBase"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iRegTime != 0) t.visit(0, false, "iRegTime", iRegTime);
			if (iLastLoginTime != 0) t.visit(1, false, "iLastLoginTime", iLastLoginTime);
			if (iThisLoginTime != 0) t.visit(2, false, "iThisLoginTime", iThisLoginTime);
			if (iOnlineTotalTime != 0) t.visit(3, false, "iOnlineTotalTime", iOnlineTotalTime);
			if (iTotalLoginTimes != 0) t.visit(4, false, "iTotalLoginTimes", iTotalLoginTimes);
			if (iTotalLoginDays != 0) t.visit(5, false, "iTotalLoginDays", iTotalLoginDays);
			if (iContinuousLoginDays != 0) t.visit(6, false, "iContinuousLoginDays", iContinuousLoginDays);
			if (iLogoutTime != 0) t.visit(7, false, "iLogoutTime", iLogoutTime);
			if (iTotalCoin != 0) t.visit(8, false, "iTotalCoin", iTotalCoin);
			if (iTotalRedDiamond != 0) t.visit(9, false, "iTotalRedDiamond", iTotalRedDiamond);
			if (iTotalBlueDiamond != 0) t.visit(10, false, "iTotalBlueDiamond", iTotalBlueDiamond);
		}
		else
		{
			t.visit(0, false, "iRegTime", iRegTime);
			t.visit(1, false, "iLastLoginTime", iLastLoginTime);
			t.visit(2, false, "iThisLoginTime", iThisLoginTime);
			t.visit(3, false, "iOnlineTotalTime", iOnlineTotalTime);
			t.visit(4, false, "iTotalLoginTimes", iTotalLoginTimes);
			t.visit(5, false, "iTotalLoginDays", iTotalLoginDays);
			t.visit(6, false, "iContinuousLoginDays", iContinuousLoginDays);
			t.visit(7, false, "iLogoutTime", iLogoutTime);
			t.visit(8, false, "iTotalCoin", iTotalCoin);
			t.visit(9, false, "iTotalRedDiamond", iTotalRedDiamond);
			t.visit(10, false, "iTotalBlueDiamond", iTotalBlueDiamond);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iRegTime != 0) t.visit(0, false, "iRegTime", iRegTime);
			if (iLastLoginTime != 0) t.visit(1, false, "iLastLoginTime", iLastLoginTime);
			if (iThisLoginTime != 0) t.visit(2, false, "iThisLoginTime", iThisLoginTime);
			if (iOnlineTotalTime != 0) t.visit(3, false, "iOnlineTotalTime", iOnlineTotalTime);
			if (iTotalLoginTimes != 0) t.visit(4, false, "iTotalLoginTimes", iTotalLoginTimes);
			if (iTotalLoginDays != 0) t.visit(5, false, "iTotalLoginDays", iTotalLoginDays);
			if (iContinuousLoginDays != 0) t.visit(6, false, "iContinuousLoginDays", iContinuousLoginDays);
			if (iLogoutTime != 0) t.visit(7, false, "iLogoutTime", iLogoutTime);
			if (iTotalCoin != 0) t.visit(8, false, "iTotalCoin", iTotalCoin);
			if (iTotalRedDiamond != 0) t.visit(9, false, "iTotalRedDiamond", iTotalRedDiamond);
			if (iTotalBlueDiamond != 0) t.visit(10, false, "iTotalBlueDiamond", iTotalBlueDiamond);
		}
		else
		{
			t.visit(0, false, "iRegTime", iRegTime);
			t.visit(1, false, "iLastLoginTime", iLastLoginTime);
			t.visit(2, false, "iThisLoginTime", iThisLoginTime);
			t.visit(3, false, "iOnlineTotalTime", iOnlineTotalTime);
			t.visit(4, false, "iTotalLoginTimes", iTotalLoginTimes);
			t.visit(5, false, "iTotalLoginDays", iTotalLoginDays);
			t.visit(6, false, "iContinuousLoginDays", iContinuousLoginDays);
			t.visit(7, false, "iLogoutTime", iLogoutTime);
			t.visit(8, false, "iTotalCoin", iTotalCoin);
			t.visit(9, false, "iTotalRedDiamond", iTotalRedDiamond);
			t.visit(10, false, "iTotalBlueDiamond", iTotalBlueDiamond);
		}
	}
	void swap(CacheRoleBase &b)
	{
		using std::swap;
		swap(iRegTime, b.iRegTime);
		swap(iLastLoginTime, b.iLastLoginTime);
		swap(iThisLoginTime, b.iThisLoginTime);
		swap(iOnlineTotalTime, b.iOnlineTotalTime);
		swap(iTotalLoginTimes, b.iTotalLoginTimes);
		swap(iTotalLoginDays, b.iTotalLoginDays);
		swap(iContinuousLoginDays, b.iContinuousLoginDays);
		swap(iLogoutTime, b.iLogoutTime);
		swap(iTotalCoin, b.iTotalCoin);
		swap(iTotalRedDiamond, b.iTotalRedDiamond);
		swap(iTotalBlueDiamond, b.iTotalBlueDiamond);
	}
	bool operator== (const CacheRoleBase &rhs) const
	{
		return iRegTime == rhs.iRegTime
			&& iLastLoginTime == rhs.iLastLoginTime
			&& iThisLoginTime == rhs.iThisLoginTime
			&& iOnlineTotalTime == rhs.iOnlineTotalTime
			&& iTotalLoginTimes == rhs.iTotalLoginTimes
			&& iTotalLoginDays == rhs.iTotalLoginDays
			&& iContinuousLoginDays == rhs.iContinuousLoginDays
			&& iLogoutTime == rhs.iLogoutTime
			&& iTotalCoin == rhs.iTotalCoin
			&& iTotalRedDiamond == rhs.iTotalRedDiamond
			&& iTotalBlueDiamond == rhs.iTotalBlueDiamond;
	}
	bool operator!= (const CacheRoleBase &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheRoleAttr
{
	uint32_t iExp;
	uint32_t iLevel;
	uint32_t iCoin;
	uint32_t iRedDiamond;
	uint32_t iBlueDiamond;
	uint32_t iVip;

	CacheRoleAttr(): 
		iExp(0), 
		iLevel(0), 
		iCoin(0), 
		iRedDiamond(0), 
		iBlueDiamond(0), 
		iVip(0)
	{
	}
	const char *getName() const { return "CacheRoleAttr"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iExp != 0) t.visit(0, false, "iExp", iExp);
			if (iLevel != 0) t.visit(1, false, "iLevel", iLevel);
			if (iCoin != 0) t.visit(2, false, "iCoin", iCoin);
			if (iRedDiamond != 0) t.visit(3, false, "iRedDiamond", iRedDiamond);
			if (iBlueDiamond != 0) t.visit(4, false, "iBlueDiamond", iBlueDiamond);
			if (iVip != 0) t.visit(5, false, "iVip", iVip);
		}
		else
		{
			t.visit(0, false, "iExp", iExp);
			t.visit(1, false, "iLevel", iLevel);
			t.visit(2, false, "iCoin", iCoin);
			t.visit(3, false, "iRedDiamond", iRedDiamond);
			t.visit(4, false, "iBlueDiamond", iBlueDiamond);
			t.visit(5, false, "iVip", iVip);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iExp != 0) t.visit(0, false, "iExp", iExp);
			if (iLevel != 0) t.visit(1, false, "iLevel", iLevel);
			if (iCoin != 0) t.visit(2, false, "iCoin", iCoin);
			if (iRedDiamond != 0) t.visit(3, false, "iRedDiamond", iRedDiamond);
			if (iBlueDiamond != 0) t.visit(4, false, "iBlueDiamond", iBlueDiamond);
			if (iVip != 0) t.visit(5, false, "iVip", iVip);
		}
		else
		{
			t.visit(0, false, "iExp", iExp);
			t.visit(1, false, "iLevel", iLevel);
			t.visit(2, false, "iCoin", iCoin);
			t.visit(3, false, "iRedDiamond", iRedDiamond);
			t.visit(4, false, "iBlueDiamond", iBlueDiamond);
			t.visit(5, false, "iVip", iVip);
		}
	}
	void swap(CacheRoleAttr &b)
	{
		using std::swap;
		swap(iExp, b.iExp);
		swap(iLevel, b.iLevel);
		swap(iCoin, b.iCoin);
		swap(iRedDiamond, b.iRedDiamond);
		swap(iBlueDiamond, b.iBlueDiamond);
		swap(iVip, b.iVip);
	}
	bool operator== (const CacheRoleAttr &rhs) const
	{
		return iExp == rhs.iExp
			&& iLevel == rhs.iLevel
			&& iCoin == rhs.iCoin
			&& iRedDiamond == rhs.iRedDiamond
			&& iBlueDiamond == rhs.iBlueDiamond
			&& iVip == rhs.iVip;
	}
	bool operator!= (const CacheRoleAttr &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct StatisticsData
{
	uint32_t iTotal;
	uint32_t iWin;

	StatisticsData(): 
		iTotal(0), 
		iWin(0)
	{
	}
	const char *getName() const { return "StatisticsData"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iTotal != 0) t.visit(0, false, "iTotal", iTotal);
			if (iWin != 0) t.visit(1, false, "iWin", iWin);
		}
		else
		{
			t.visit(0, false, "iTotal", iTotal);
			t.visit(1, false, "iWin", iWin);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iTotal != 0) t.visit(0, false, "iTotal", iTotal);
			if (iWin != 0) t.visit(1, false, "iWin", iWin);
		}
		else
		{
			t.visit(0, false, "iTotal", iTotal);
			t.visit(1, false, "iWin", iWin);
		}
	}
	void swap(StatisticsData &b)
	{
		using std::swap;
		swap(iTotal, b.iTotal);
		swap(iWin, b.iWin);
	}
	bool operator== (const StatisticsData &rhs) const
	{
		return iTotal == rhs.iTotal
			&& iWin == rhs.iWin;
	}
	bool operator!= (const StatisticsData &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheStatistics
{
	uint32_t iMVP;
	map<uint32_t, EELCache::StatisticsData> mStatistics;

	CacheStatistics(): 
		iMVP(0)
	{
	}
	const char *getName() const { return "CacheStatistics"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iMVP != 0) t.visit(0, false, "iMVP", iMVP);
			if (!mStatistics.empty()) t.visit(1, false, "mStatistics", mStatistics);
		}
		else
		{
			t.visit(0, false, "iMVP", iMVP);
			t.visit(1, false, "mStatistics", mStatistics);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iMVP != 0) t.visit(0, false, "iMVP", iMVP);
			if (!mStatistics.empty()) t.visit(1, false, "mStatistics", mStatistics);
		}
		else
		{
			t.visit(0, false, "iMVP", iMVP);
			t.visit(1, false, "mStatistics", mStatistics);
		}
	}
	void swap(CacheStatistics &b)
	{
		using std::swap;
		swap(iMVP, b.iMVP);
		swap(mStatistics, b.mStatistics);
	}
	bool operator== (const CacheStatistics &rhs) const
	{
		return iMVP == rhs.iMVP
			&& mStatistics == rhs.mStatistics;
	}
	bool operator!= (const CacheStatistics &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheHero
{
	uint32_t iHeroId;
	uint32_t iExp;
	uint32_t iLevel;
	uint32_t iStar;
	uint32_t iSkillUnLockFlag;
	vector<uint32_t> vSkin;
	map<uint32_t, EELCache::StatisticsData> mStatistics;

	CacheHero(): 
		iHeroId(0), 
		iExp(0), 
		iLevel(0), 
		iStar(0), 
		iSkillUnLockFlag(0)
	{
	}
	const char *getName() const { return "CacheHero"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iHeroId != 0) t.visit(0, false, "iHeroId", iHeroId);
			if (iExp != 0) t.visit(1, false, "iExp", iExp);
			if (iLevel != 0) t.visit(2, false, "iLevel", iLevel);
			if (iStar != 0) t.visit(3, false, "iStar", iStar);
			if (iSkillUnLockFlag != 0) t.visit(6, false, "iSkillUnLockFlag", iSkillUnLockFlag);
			if (!vSkin.empty()) t.visit(7, false, "vSkin", vSkin);
			if (!mStatistics.empty()) t.visit(8, false, "mStatistics", mStatistics);
		}
		else
		{
			t.visit(0, false, "iHeroId", iHeroId);
			t.visit(1, false, "iExp", iExp);
			t.visit(2, false, "iLevel", iLevel);
			t.visit(3, false, "iStar", iStar);
			t.visit(6, false, "iSkillUnLockFlag", iSkillUnLockFlag);
			t.visit(7, false, "vSkin", vSkin);
			t.visit(8, false, "mStatistics", mStatistics);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iHeroId != 0) t.visit(0, false, "iHeroId", iHeroId);
			if (iExp != 0) t.visit(1, false, "iExp", iExp);
			if (iLevel != 0) t.visit(2, false, "iLevel", iLevel);
			if (iStar != 0) t.visit(3, false, "iStar", iStar);
			if (iSkillUnLockFlag != 0) t.visit(6, false, "iSkillUnLockFlag", iSkillUnLockFlag);
			if (!vSkin.empty()) t.visit(7, false, "vSkin", vSkin);
			if (!mStatistics.empty()) t.visit(8, false, "mStatistics", mStatistics);
		}
		else
		{
			t.visit(0, false, "iHeroId", iHeroId);
			t.visit(1, false, "iExp", iExp);
			t.visit(2, false, "iLevel", iLevel);
			t.visit(3, false, "iStar", iStar);
			t.visit(6, false, "iSkillUnLockFlag", iSkillUnLockFlag);
			t.visit(7, false, "vSkin", vSkin);
			t.visit(8, false, "mStatistics", mStatistics);
		}
	}
	void swap(CacheHero &b)
	{
		using std::swap;
		swap(iHeroId, b.iHeroId);
		swap(iExp, b.iExp);
		swap(iLevel, b.iLevel);
		swap(iStar, b.iStar);
		swap(iSkillUnLockFlag, b.iSkillUnLockFlag);
		swap(vSkin, b.vSkin);
		swap(mStatistics, b.mStatistics);
	}
	bool operator== (const CacheHero &rhs) const
	{
		return iHeroId == rhs.iHeroId
			&& iExp == rhs.iExp
			&& iLevel == rhs.iLevel
			&& iStar == rhs.iStar
			&& iSkillUnLockFlag == rhs.iSkillUnLockFlag
			&& vSkin == rhs.vSkin
			&& mStatistics == rhs.mStatistics;
	}
	bool operator!= (const CacheHero &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheAllHero
{
	vector<EELCache::CacheHero> vHeroList;

	CacheAllHero() {}
	const char *getName() const { return "CacheAllHero"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (!vHeroList.empty()) t.visit(0, false, "vHeroList", vHeroList);
		}
		else
		{
			t.visit(0, false, "vHeroList", vHeroList);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (!vHeroList.empty()) t.visit(0, false, "vHeroList", vHeroList);
		}
		else
		{
			t.visit(0, false, "vHeroList", vHeroList);
		}
	}
	void swap(CacheAllHero &b)
	{
		using std::swap;
		swap(vHeroList, b.vHeroList);
	}
	bool operator== (const CacheAllHero &rhs) const
	{
		return vHeroList == rhs.vHeroList;
	}
	bool operator!= (const CacheAllHero &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheMarket
{
	map<uint32_t, uint32_t> mBuyTimes;

	CacheMarket() {}
	const char *getName() const { return "CacheMarket"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (!mBuyTimes.empty()) t.visit(0, false, "mBuyTimes", mBuyTimes);
		}
		else
		{
			t.visit(0, false, "mBuyTimes", mBuyTimes);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (!mBuyTimes.empty()) t.visit(0, false, "mBuyTimes", mBuyTimes);
		}
		else
		{
			t.visit(0, false, "mBuyTimes", mBuyTimes);
		}
	}
	void swap(CacheMarket &b)
	{
		using std::swap;
		swap(mBuyTimes, b.mBuyTimes);
	}
	bool operator== (const CacheMarket &rhs) const
	{
		return mBuyTimes == rhs.mBuyTimes;
	}
	bool operator!= (const CacheMarket &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct RunePageData
{
	uint32_t iId;
	string strName;
	map<uint32_t, uint32_t> mRune;

	RunePageData(): 
		iId(0)
	{
	}
	const char *getName() const { return "RunePageData"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iId != 0) t.visit(0, false, "iId", iId);
			if (!strName.empty()) t.visit(1, false, "strName", strName);
			if (!mRune.empty()) t.visit(2, false, "mRune", mRune);
		}
		else
		{
			t.visit(0, false, "iId", iId);
			t.visit(1, false, "strName", strName);
			t.visit(2, false, "mRune", mRune);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iId != 0) t.visit(0, false, "iId", iId);
			if (!strName.empty()) t.visit(1, false, "strName", strName);
			if (!mRune.empty()) t.visit(2, false, "mRune", mRune);
		}
		else
		{
			t.visit(0, false, "iId", iId);
			t.visit(1, false, "strName", strName);
			t.visit(2, false, "mRune", mRune);
		}
	}
	void swap(RunePageData &b)
	{
		using std::swap;
		swap(iId, b.iId);
		swap(strName, b.strName);
		swap(mRune, b.mRune);
	}
	bool operator== (const RunePageData &rhs) const
	{
		return iId == rhs.iId
			&& strName == rhs.strName
			&& mRune == rhs.mRune;
	}
	bool operator!= (const RunePageData &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CachRune
{
	vector<EELCache::RunePageData> vRunePage;
	uint32_t iSlotUnLockFlag;

	CachRune(): 
		iSlotUnLockFlag(0)
	{
	}
	const char *getName() const { return "CachRune"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (!vRunePage.empty()) t.visit(0, false, "vRunePage", vRunePage);
			if (iSlotUnLockFlag != 0) t.visit(1, false, "iSlotUnLockFlag", iSlotUnLockFlag);
		}
		else
		{
			t.visit(0, false, "vRunePage", vRunePage);
			t.visit(1, false, "iSlotUnLockFlag", iSlotUnLockFlag);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (!vRunePage.empty()) t.visit(0, false, "vRunePage", vRunePage);
			if (iSlotUnLockFlag != 0) t.visit(1, false, "iSlotUnLockFlag", iSlotUnLockFlag);
		}
		else
		{
			t.visit(0, false, "vRunePage", vRunePage);
			t.visit(1, false, "iSlotUnLockFlag", iSlotUnLockFlag);
		}
	}
	void swap(CachRune &b)
	{
		using std::swap;
		swap(vRunePage, b.vRunePage);
		swap(iSlotUnLockFlag, b.iSlotUnLockFlag);
	}
	bool operator== (const CachRune &rhs) const
	{
		return vRunePage == rhs.vRunePage
			&& iSlotUnLockFlag == rhs.iSlotUnLockFlag;
	}
	bool operator!= (const CachRune &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CachFaceInfo
{
	uint32_t iFaceId;
	uint32_t iFaceFrameId;
	uint64_t iFaceFrameFlag;

	CachFaceInfo(): 
		iFaceId(0), 
		iFaceFrameId(0), 
		iFaceFrameFlag(0)
	{
	}
	const char *getName() const { return "CachFaceInfo"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iFaceId != 0) t.visit(0, false, "iFaceId", iFaceId);
			if (iFaceFrameId != 0) t.visit(1, false, "iFaceFrameId", iFaceFrameId);
			if (iFaceFrameFlag != 0) t.visit(2, false, "iFaceFrameFlag", iFaceFrameFlag);
		}
		else
		{
			t.visit(0, false, "iFaceId", iFaceId);
			t.visit(1, false, "iFaceFrameId", iFaceFrameId);
			t.visit(2, false, "iFaceFrameFlag", iFaceFrameFlag);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iFaceId != 0) t.visit(0, false, "iFaceId", iFaceId);
			if (iFaceFrameId != 0) t.visit(1, false, "iFaceFrameId", iFaceFrameId);
			if (iFaceFrameFlag != 0) t.visit(2, false, "iFaceFrameFlag", iFaceFrameFlag);
		}
		else
		{
			t.visit(0, false, "iFaceId", iFaceId);
			t.visit(1, false, "iFaceFrameId", iFaceFrameId);
			t.visit(2, false, "iFaceFrameFlag", iFaceFrameFlag);
		}
	}
	void swap(CachFaceInfo &b)
	{
		using std::swap;
		swap(iFaceId, b.iFaceId);
		swap(iFaceFrameId, b.iFaceFrameId);
		swap(iFaceFrameFlag, b.iFaceFrameFlag);
	}
	bool operator== (const CachFaceInfo &rhs) const
	{
		return iFaceId == rhs.iFaceId
			&& iFaceFrameId == rhs.iFaceFrameId
			&& iFaceFrameFlag == rhs.iFaceFrameFlag;
	}
	bool operator!= (const CachFaceInfo &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheRoom
{
	uint32_t iScore;
	uint32_t iWinTimes;
	uint32_t iLossTimes;
	uint32_t iReputation;

	CacheRoom(): 
		iScore(0), 
		iWinTimes(0), 
		iLossTimes(0), 
		iReputation(0)
	{
	}
	const char *getName() const { return "CacheRoom"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iScore != 0) t.visit(1, false, "iScore", iScore);
			if (iWinTimes != 0) t.visit(2, false, "iWinTimes", iWinTimes);
			if (iLossTimes != 0) t.visit(3, false, "iLossTimes", iLossTimes);
			if (iReputation != 0) t.visit(4, false, "iReputation", iReputation);
		}
		else
		{
			t.visit(1, false, "iScore", iScore);
			t.visit(2, false, "iWinTimes", iWinTimes);
			t.visit(3, false, "iLossTimes", iLossTimes);
			t.visit(4, false, "iReputation", iReputation);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iScore != 0) t.visit(1, false, "iScore", iScore);
			if (iWinTimes != 0) t.visit(2, false, "iWinTimes", iWinTimes);
			if (iLossTimes != 0) t.visit(3, false, "iLossTimes", iLossTimes);
			if (iReputation != 0) t.visit(4, false, "iReputation", iReputation);
		}
		else
		{
			t.visit(1, false, "iScore", iScore);
			t.visit(2, false, "iWinTimes", iWinTimes);
			t.visit(3, false, "iLossTimes", iLossTimes);
			t.visit(4, false, "iReputation", iReputation);
		}
	}
	void swap(CacheRoom &b)
	{
		using std::swap;
		swap(iScore, b.iScore);
		swap(iWinTimes, b.iWinTimes);
		swap(iLossTimes, b.iLossTimes);
		swap(iReputation, b.iReputation);
	}
	bool operator== (const CacheRoom &rhs) const
	{
		return iScore == rhs.iScore
			&& iWinTimes == rhs.iWinTimes
			&& iLossTimes == rhs.iLossTimes
			&& iReputation == rhs.iReputation;
	}
	bool operator!= (const CacheRoom &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheItem
{
	uint64_t iItemUid;
	uint32_t iBaseId;
	uint32_t iNum;

	CacheItem(): 
		iItemUid(0), 
		iBaseId(0), 
		iNum(0)
	{
	}
	const char *getName() const { return "CacheItem"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iItemUid != 0) t.visit(0, false, "iItemUid", iItemUid);
			if (iBaseId != 0) t.visit(1, false, "iBaseId", iBaseId);
			if (iNum != 0) t.visit(2, false, "iNum", iNum);
		}
		else
		{
			t.visit(0, false, "iItemUid", iItemUid);
			t.visit(1, false, "iBaseId", iBaseId);
			t.visit(2, false, "iNum", iNum);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iItemUid != 0) t.visit(0, false, "iItemUid", iItemUid);
			if (iBaseId != 0) t.visit(1, false, "iBaseId", iBaseId);
			if (iNum != 0) t.visit(2, false, "iNum", iNum);
		}
		else
		{
			t.visit(0, false, "iItemUid", iItemUid);
			t.visit(1, false, "iBaseId", iBaseId);
			t.visit(2, false, "iNum", iNum);
		}
	}
	void swap(CacheItem &b)
	{
		using std::swap;
		swap(iItemUid, b.iItemUid);
		swap(iBaseId, b.iBaseId);
		swap(iNum, b.iNum);
	}
	bool operator== (const CacheItem &rhs) const
	{
		return iItemUid == rhs.iItemUid
			&& iBaseId == rhs.iBaseId
			&& iNum == rhs.iNum;
	}
	bool operator!= (const CacheItem &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheAllItem
{
	vector<EELCache::CacheItem> vItemList;

	CacheAllItem() {}
	const char *getName() const { return "CacheAllItem"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (!vItemList.empty()) t.visit(0, false, "vItemList", vItemList);
		}
		else
		{
			t.visit(0, false, "vItemList", vItemList);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (!vItemList.empty()) t.visit(0, false, "vItemList", vItemList);
		}
		else
		{
			t.visit(0, false, "vItemList", vItemList);
		}
	}
	void swap(CacheAllItem &b)
	{
		using std::swap;
		swap(vItemList, b.vItemList);
	}
	bool operator== (const CacheAllItem &rhs) const
	{
		return vItemList == rhs.vItemList;
	}
	bool operator!= (const CacheAllItem &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheFriendApply
{
	uint64_t iUid;
	uint32_t iTemplateId;
	string sWords;
	uint32_t iTime;

	CacheFriendApply(): 
		iUid(0), 
		iTemplateId(0), 
		iTime(0)
	{
	}
	const char *getName() const { return "CacheFriendApply"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iUid != 0) t.visit(0, false, "iUid", iUid);
			if (iTemplateId != 0) t.visit(1, false, "iTemplateId", iTemplateId);
			if (!sWords.empty()) t.visit(2, false, "sWords", sWords);
			if (iTime != 0) t.visit(3, false, "iTime", iTime);
		}
		else
		{
			t.visit(0, false, "iUid", iUid);
			t.visit(1, false, "iTemplateId", iTemplateId);
			t.visit(2, false, "sWords", sWords);
			t.visit(3, false, "iTime", iTime);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iUid != 0) t.visit(0, false, "iUid", iUid);
			if (iTemplateId != 0) t.visit(1, false, "iTemplateId", iTemplateId);
			if (!sWords.empty()) t.visit(2, false, "sWords", sWords);
			if (iTime != 0) t.visit(3, false, "iTime", iTime);
		}
		else
		{
			t.visit(0, false, "iUid", iUid);
			t.visit(1, false, "iTemplateId", iTemplateId);
			t.visit(2, false, "sWords", sWords);
			t.visit(3, false, "iTime", iTime);
		}
	}
	void swap(CacheFriendApply &b)
	{
		using std::swap;
		swap(iUid, b.iUid);
		swap(iTemplateId, b.iTemplateId);
		swap(sWords, b.sWords);
		swap(iTime, b.iTime);
	}
	bool operator== (const CacheFriendApply &rhs) const
	{
		return iUid == rhs.iUid
			&& iTemplateId == rhs.iTemplateId
			&& sWords == rhs.sWords
			&& iTime == rhs.iTime;
	}
	bool operator!= (const CacheFriendApply &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheFriend
{
	vector<uint64_t> vFriend;
	vector<EELCache::CacheFriendApply> vApply;
	vector<uint64_t> vBlack;
	bool bRejectFriend;

	CacheFriend(): 
		bRejectFriend(false)
	{
	}
	const char *getName() const { return "CacheFriend"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (!vFriend.empty()) t.visit(0, false, "vFriend", vFriend);
			if (!vApply.empty()) t.visit(1, false, "vApply", vApply);
			if (!vBlack.empty()) t.visit(2, false, "vBlack", vBlack);
			if (bRejectFriend != false) t.visit(3, false, "bRejectFriend", bRejectFriend);
		}
		else
		{
			t.visit(0, false, "vFriend", vFriend);
			t.visit(1, false, "vApply", vApply);
			t.visit(2, false, "vBlack", vBlack);
			t.visit(3, false, "bRejectFriend", bRejectFriend);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (!vFriend.empty()) t.visit(0, false, "vFriend", vFriend);
			if (!vApply.empty()) t.visit(1, false, "vApply", vApply);
			if (!vBlack.empty()) t.visit(2, false, "vBlack", vBlack);
			if (bRejectFriend != false) t.visit(3, false, "bRejectFriend", bRejectFriend);
		}
		else
		{
			t.visit(0, false, "vFriend", vFriend);
			t.visit(1, false, "vApply", vApply);
			t.visit(2, false, "vBlack", vBlack);
			t.visit(3, false, "bRejectFriend", bRejectFriend);
		}
	}
	void swap(CacheFriend &b)
	{
		using std::swap;
		swap(vFriend, b.vFriend);
		swap(vApply, b.vApply);
		swap(vBlack, b.vBlack);
		swap(bRejectFriend, b.bRejectFriend);
	}
	bool operator== (const CacheFriend &rhs) const
	{
		return vFriend == rhs.vFriend
			&& vApply == rhs.vApply
			&& vBlack == rhs.vBlack
			&& bRejectFriend == rhs.bRejectFriend;
	}
	bool operator!= (const CacheFriend &rhs) const
	{
		return !((*this) == rhs);
	}
};

struct CacheRole
{
	uint32_t iVersion;
	uint64_t iUid;
	string sName;
	EELCache::CacheRoleBase stBase;
	EELCache::CacheRoleAttr stAttr;
	EELCache::CacheAllHero stAllHero;
	EELCache::CacheRoom stRoom;
	EELCache::CacheAllItem stAllItem;
	EELCache::CacheFriend stFriend;
	EELCache::CacheMarket stMarket;
	EELCache::CachRune stRune;
	EELCache::CachFaceInfo stFace;
	EELCache::CacheStatistics stStatistics;

	CacheRole(): 
		iVersion(0), 
		iUid(0)
	{
	}
	const char *getName() const { return "CacheRole"; } 
	template <typename T>
	void visit(T &t, bool bOpt) 
	{
		if (!bOpt)
		{
			if (iVersion != 0) t.visit(0, false, "iVersion", iVersion);
			t.visit(1, true, "iUid", iUid);
			if (!sName.empty()) t.visit(2, false, "sName", sName);
			t.visit(3, false, "stBase", stBase);
			t.visit(4, false, "stAttr", stAttr);
			t.visit(5, false, "stAllHero", stAllHero);
			t.visit(6, false, "stRoom", stRoom);
			t.visit(7, false, "stAllItem", stAllItem);
			t.visit(9, false, "stFriend", stFriend);
			t.visit(10, false, "stMarket", stMarket);
			t.visit(11, false, "stRune", stRune);
			t.visit(12, false, "stFace", stFace);
			t.visit(13, false, "stStatistics", stStatistics);
		}
		else
		{
			t.visit(0, false, "iVersion", iVersion);
			t.visit(1, true, "iUid", iUid);
			t.visit(2, false, "sName", sName);
			t.visit(3, false, "stBase", stBase);
			t.visit(4, false, "stAttr", stAttr);
			t.visit(5, false, "stAllHero", stAllHero);
			t.visit(6, false, "stRoom", stRoom);
			t.visit(7, false, "stAllItem", stAllItem);
			t.visit(9, false, "stFriend", stFriend);
			t.visit(10, false, "stMarket", stMarket);
			t.visit(11, false, "stRune", stRune);
			t.visit(12, false, "stFace", stFace);
			t.visit(13, false, "stStatistics", stStatistics);
		}
	}
	template <typename T>
	void visit(T &t, bool bOpt) const 
	{
		if (!bOpt)
		{
			if (iVersion != 0) t.visit(0, false, "iVersion", iVersion);
			t.visit(1, true, "iUid", iUid);
			if (!sName.empty()) t.visit(2, false, "sName", sName);
			t.visit(3, false, "stBase", stBase);
			t.visit(4, false, "stAttr", stAttr);
			t.visit(5, false, "stAllHero", stAllHero);
			t.visit(6, false, "stRoom", stRoom);
			t.visit(7, false, "stAllItem", stAllItem);
			t.visit(9, false, "stFriend", stFriend);
			t.visit(10, false, "stMarket", stMarket);
			t.visit(11, false, "stRune", stRune);
			t.visit(12, false, "stFace", stFace);
			t.visit(13, false, "stStatistics", stStatistics);
		}
		else
		{
			t.visit(0, false, "iVersion", iVersion);
			t.visit(1, true, "iUid", iUid);
			t.visit(2, false, "sName", sName);
			t.visit(3, false, "stBase", stBase);
			t.visit(4, false, "stAttr", stAttr);
			t.visit(5, false, "stAllHero", stAllHero);
			t.visit(6, false, "stRoom", stRoom);
			t.visit(7, false, "stAllItem", stAllItem);
			t.visit(9, false, "stFriend", stFriend);
			t.visit(10, false, "stMarket", stMarket);
			t.visit(11, false, "stRune", stRune);
			t.visit(12, false, "stFace", stFace);
			t.visit(13, false, "stStatistics", stStatistics);
		}
	}
	void swap(CacheRole &b)
	{
		using std::swap;
		swap(iVersion, b.iVersion);
		swap(iUid, b.iUid);
		swap(sName, b.sName);
		swap(stBase, b.stBase);
		swap(stAttr, b.stAttr);
		swap(stAllHero, b.stAllHero);
		swap(stRoom, b.stRoom);
		swap(stAllItem, b.stAllItem);
		swap(stFriend, b.stFriend);
		swap(stMarket, b.stMarket);
		swap(stRune, b.stRune);
		swap(stFace, b.stFace);
		swap(stStatistics, b.stStatistics);
	}
	bool operator== (const CacheRole &rhs) const
	{
		return iVersion == rhs.iVersion
			&& iUid == rhs.iUid
			&& sName == rhs.sName
			&& stBase == rhs.stBase
			&& stAttr == rhs.stAttr
			&& stAllHero == rhs.stAllHero
			&& stRoom == rhs.stRoom
			&& stAllItem == rhs.stAllItem
			&& stFriend == rhs.stFriend
			&& stMarket == rhs.stMarket
			&& stRune == rhs.stRune
			&& stFace == rhs.stFace
			&& stStatistics == rhs.stStatistics;
	}
	bool operator!= (const CacheRole &rhs) const
	{
		return !((*this) == rhs);
	}
};

}

namespace std
{
inline void swap(EELCache::CacheIDNum &a, EELCache::CacheIDNum &b) { a.swap(b); }
inline void swap(EELCache::CacheRoleBase &a, EELCache::CacheRoleBase &b) { a.swap(b); }
inline void swap(EELCache::CacheRoleAttr &a, EELCache::CacheRoleAttr &b) { a.swap(b); }
inline void swap(EELCache::StatisticsData &a, EELCache::StatisticsData &b) { a.swap(b); }
inline void swap(EELCache::CacheStatistics &a, EELCache::CacheStatistics &b) { a.swap(b); }
inline void swap(EELCache::CacheHero &a, EELCache::CacheHero &b) { a.swap(b); }
inline void swap(EELCache::CacheAllHero &a, EELCache::CacheAllHero &b) { a.swap(b); }
inline void swap(EELCache::CacheMarket &a, EELCache::CacheMarket &b) { a.swap(b); }
inline void swap(EELCache::RunePageData &a, EELCache::RunePageData &b) { a.swap(b); }
inline void swap(EELCache::CachRune &a, EELCache::CachRune &b) { a.swap(b); }
inline void swap(EELCache::CachFaceInfo &a, EELCache::CachFaceInfo &b) { a.swap(b); }
inline void swap(EELCache::CacheRoom &a, EELCache::CacheRoom &b) { a.swap(b); }
inline void swap(EELCache::CacheItem &a, EELCache::CacheItem &b) { a.swap(b); }
inline void swap(EELCache::CacheAllItem &a, EELCache::CacheAllItem &b) { a.swap(b); }
inline void swap(EELCache::CacheFriendApply &a, EELCache::CacheFriendApply &b) { a.swap(b); }
inline void swap(EELCache::CacheFriend &a, EELCache::CacheFriend &b) { a.swap(b); }
inline void swap(EELCache::CacheRole &a, EELCache::CacheRole &b) { a.swap(b); }
}

#endif
