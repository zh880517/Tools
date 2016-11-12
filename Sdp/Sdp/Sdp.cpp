// Sdp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include "Sdp.h"
#include "CacheRole.h"

int main()
{
	EELCache::CacheRole stRole;
	stRole.iUid = 100011111;
	stRole.iVersion = 100112;
	stRole.sName = "Test";
	stRole.stFace.iFaceFrameFlag = 1;
	stRole.stFace.iFaceFrameId = 2;
	stRole.stFace.iFaceId = 13213;
	stRole.stFriend.vFriend.push_back(111);

	std::cout << printSdp(stRole);


	std::string strData = sdpToString(stRole);
	std::cout <<"ѹ�������ݳ��� = "<< strData.size() << " �������ݣ� " << strData << std::endl;
	{
		EELCache::CacheRole stOut;
		stringToSdp(strData, stOut);
		std::cout << printSdp(stOut);
	}
	SdpPacker packer;
	packer.pack(0, 1);
	std::cout <<  packer.getData();

	system("pause");
    return 0;
}

