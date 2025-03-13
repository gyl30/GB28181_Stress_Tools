#pragma once
#include "bits.h"

#define PS_HDR_LEN  14
#define SYS_HDR_LEN 18
#define PSM_HDR_LEN 24
#define PES_HDR_LEN 19
#define RTP_HDR_LEN 12

#define RTP_PKT_END 1
#define RTP_PKT_APPENDING 0

/***
 *@remark:   psͷ�ķ�װ,����ľ������ݵ���д�Ѿ�ռλ�����Բο���׼
 *@param :   pData  [in] ���psͷ���ݵĵ�ַ
 *           s64Src [in] ʱ���
 *@return:   0 success, others failed
*/
int gb28181_make_ps_header(char *pData, int64_t s64Scr);



/***
 *@remark:   sysͷ�ķ�װ,����ľ������ݵ���д�Ѿ�ռλ�����Բο���׼
 *@param :   pData  [in] ���psͷ���ݵĵ�ַ
 *@return:   0 success, others failed
*/
int gb28181_make_sys_header(char *pData, int audioCnt);

/***
 *@remark:   psmͷ�ķ�װ,����ľ������ݵ���д�Ѿ�ռλ�����Բο���׼
 *@param :   pData  [in] ���psͷ���ݵĵ�ַ
 *@return:   0 success, others failed
*/
int gb28181_make_psm_header(char *pData);

/***
 *@remark:   pesͷ�ķ�װ,����ľ������ݵ���д�Ѿ�ռλ�����Բο���׼
 *@param :   pData      [in] ���psͷ���ݵĵ�ַ
 *           stream_id  [in] ��������
 *           paylaod_len[in] ���س���
 *           pts        [in] ʱ���
 *           dts        [in]
 *@return:   0 success, others failed
*/
int gb28181_make_pes_header(char *pData, int stream_id, int payload_len, int64_t pts, int64_t dts);

/**
 * RTPͷ��װ
 * @param pData buffer��ַ
 * @param seqNum ���
 * @param timestamp ʱ���
 * @param ssrc ��ʶ
 * @return
 */
int gb28181_make_rtp_header(char *pData, int seqNum, int64_t timestamp, int ssrc, int isEnd);