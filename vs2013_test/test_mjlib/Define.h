#pragma once

#include <list>
#include <vector>
#include "CMD_Mj.h"
#include "DefineHuTip.h"

//#define TOTAL_MJ_CARD_NUM    108               //麻将牌的总数量
#define TOTAL_DICE_NUM        2                //骰子的个数
 
//麻将牌定义
enum E_TYPE_MJ_KIND
{
	MJ_TYPE_FLOER_KIND_WAN = 0,  //万
	MJ_TYPE_FLOER_KIND_TONG,     //筒
	MJ_TYPE_FLOER_KIND_TIAO,     //条
	MJ_TYPE_FLOER_KIND_DXNB,     //东西南北
	MJ_TYPE_FLOER_KIND_ZFB,      //中发白

	MJ_TYPE_FLOER_TOTAL
};

//所有牌类型值
static const BYTE s_arrayCardType[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//饼
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//条
	0x41																//中发白
};

//3,4人转转麻将
static const BYTE arryAllMj_ZZ_4[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//饼
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//条
	0x41,

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//饼
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//条
	0x41,

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//饼
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//条
	0x41,

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,				//饼
	0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29,				//条
	0x41
};

////2人转转麻将  test
//static const BYTE arryAllMj_ZZ_2[] = 
//{
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
//	0x31, 0x32, 0x33, 0x34,                                             //东西南北
//	0x41, 0x42, 0x43,                                                   //中发白
//
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
//	0x31, 0x32, 0x33, 0x34,                                             //东西南北
//	0x41, 0x42, 0x43,                                                   //中发白
//
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
//	0x31, 0x32, 0x33, 0x34,                                             //东西南北
//	0x41, 0x42, 0x43,                                                   //中发白
//
//	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
//	0x31, 0x32, 0x33, 0x34,                                             //东西南北
//	0x41, 0x42, 0x43,                                                   //中发白
//	0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x41
//};

//2人转转麻将
static const BYTE arryAllMj_ZZ_2[] = 
{
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x31, 0x32, 0x33, 0x34,                                             //东西南北
	0x41, 0x42, 0x43,                                                   //中发白

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x31, 0x32, 0x33, 0x34,                                             //东西南北
	0x41, 0x42, 0x43,                                                   //中发白
	
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x31, 0x32, 0x33, 0x34,                                             //东西南北
	0x41, 0x42, 0x43,                                                   //中发白

	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,				//万
	0x31, 0x32, 0x33, 0x34,                                             //东西南北
	0x41, 0x42, 0x43                                                    //中发白
};

//吃碰杠节点
struct MJCPGNode
{
	BYTE byBlockCardType; //吃碰杠类型  参考BLOCK_CARD_TYPE
	BYTE bySeat;          //吃碰杠的对象
	BYTE byOutCard;       //吃碰杠别人的那张牌
	BYTE byMjCard[4];     //吃碰杠牌
};

//一块牌类型
enum BLOCK_CARD_TYPE
{	
	BLOCK_NULL	 = 0,				//无
	BLOCK_DUIZI,                    //对子
	BLOCK_SUN_CHI,					//顺序 或者 吃牌 结构
	BLOCK_KEZI_PENG,				//刻子 或者 碰子 结构,3个相同
	BLOCK_GANG_DIAN,   				//杠子--点杠,4个相同
	BLOCK_GANG_BU,   				//杠子--补杠,4个相同
	BLOCK_GANG_AN ,					//杠子--暗杠,4个相同
};

//当前操作状态
enum E_CUR_SEAT_OP_STATUS
{
	TSEAT_STATUS_OP_ING = 0,                 //正在操作中
	TSEAT_STATUS_WAIT_OTHER_OP_MYOUT_CARD,   //自己操作完,等待其他玩家操作(我出的牌其他人可能吃碰杠)
	TSEAT_STATUS_WAIT_OTHER_OP_MYGANG_CARD,  //等待其他玩家 对 我补杠的牌进行操作
	TSEAT_STATUS_OP_COMPLETE   //操作完成
};

//游戏中倒计时类型
enum E_DJS_GAME_PLAYING
{
	EGPDJS_NO        = 0,    //没有倒计时
	EGPDJS_TOUSHAIZI,        //投骰子倒计时
	EGPDJS_FAPAI,            //发牌倒计时
	EGPDJS_OUTCARD,          //出牌倒计时
	EGPDJS_WAIT_OTHERCHOOSE, //等待其他人操作倒计时
	EGPDJS_ZHUANIAO,         //抓鸟倒计时
	EGPDJS_WAITEND,          //等待结算倒计时
};

//长沙红中---麻将抓鸟数 ,对应m_unOpt2
enum E_CSHZ_MJ_OPTION4_ZHUANIAO 
{
	E_CSHZ_MJ_OP4_NIAO_NO = 0,  //无
	E_CSHZ_MJ_OP4_NIAO2   = 1,  //2个鸟
	E_CSHZ_MJ_OP4_NIAO3   = 2,  //3个鸟
	E_CSHZ_MJ_OP4_NIAO4   = 3,  //4个鸟
	E_CSHZ_MJ_OP4_NIAO6   = 4,  //6个鸟

	E_CSHZ_MJ_OP4_NIAO_MAX
};

enum E_CSHZ_MJ_OPTION2_GANG
{
	E_CSHZ_MJ_OP2_GANG_NO = 0,		//无
	E_CSHZ_MJ_OP2_GANG_1 = 0x01,	//可过后补杠
	E_CSHZ_MJ_OP2_GANG_2 = 0x02,	//可先碰后补杠
	E_CSHZ_MJ_OP2_GANG_MAX
};

enum E_CSHZ_MJ_OPTION3_HU_NIAO
{
	E_CSHZ_MJ_OP3_HU_NIAO_NO = 0,	//无
	E_CSHZ_MJ_OP3_HU_NIAO_1 = 1,	//没红中加1鸟
	E_CSHZ_MJ_OP3_HU_NIAO_2 = 2,	//没红中加2鸟
	E_CSHZ_MJ_OP3_HU_NIAO_MAX
};

//服务器保存的操作
struct SERVER_SAVE_USER_OPERATE
{
	DWORD                dwEnableAction;  //能操作的动作  参考E_ACTION_TYPE 

	BYTE                 byOutMjSeatNo;   //目标座位号 , 即吃、碰、点杠、点炮胡 谁的牌
	BYTE                 byOutMj;         //目标座位出的麻将

	std::vector<stOpCardList> vecCardList;

public:
	SERVER_SAVE_USER_OPERATE()
	{
		ClearData();
	}

	void ClearData()
	{
		dwEnableAction = 0;
		byOutMjSeatNo  = 0;
		byOutMj        = 0;
		vecCardList.clear();
	}
};