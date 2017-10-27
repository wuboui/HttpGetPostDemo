// curlDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "WinHttpClient/WinHttpClient.h"
#include "httpclient.h"
using namespace std;

wstring UTF8ToUnicode( const string &str )
{
	int  len = 0;
	len = str.length();
	int  unicodeLen = ::MultiByteToWideChar( CP_UTF8,
		0,
		str.c_str(),
		-1,
		NULL,
		0 );
	wchar_t   *pUnicode;
	pUnicode = new  wchar_t[unicodeLen + 1];
	memset(pUnicode, 0, (unicodeLen + 1)*sizeof(wchar_t));
	::MultiByteToWideChar( CP_UTF8,
		0,
		str.c_str(),
		-1,
		(LPWSTR)pUnicode,
		unicodeLen );
	wstring  rt;
	rt = ( wchar_t * )pUnicode;
	delete  pUnicode;

	return  rt;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string strResponse;
	//curl CHttpClient Test
	CHttpClient client;
	client.Gets("https://kyfw.12306.cn/otn/leftTicket/query?leftTicketDTO.train_date=2017-10-28&leftTicketDTO.from_station=BJP&leftTicketDTO.to_station=SHH&purpose_codes=ADULT",strResponse);
	MessageBoxW(NULL,UTF8ToUnicode(strResponse).c_str(),L"https://www.12306.cn",MB_OK);
	strResponse.clear();
	client.Gets("https://www.12306.cn",strResponse);
	MessageBoxW(NULL,UTF8ToUnicode(strResponse).c_str(),L"https://www.alipay.com",MB_OK);
	strResponse.clear();
 	client.Get("http://so.baiduyun.me/search.php?wd=google",strResponse);
	MessageBoxW(NULL,UTF8ToUnicode(strResponse).c_str(),L"http://so.baiduyun.me/search.php?wd=google",MB_OK);
	strResponse.clear();
	client.Post("http://so.baiduyun.me/search.php","wd=google",strResponse);
	MessageBoxW(NULL,UTF8ToUnicode(strResponse).c_str(),L"http://so.baiduyun.me/search.php?wd=google",MB_OK);

	//winhttp WinHttpClient Test
	WinHttpClient WinClient(L"https://itunes.apple.com/cn/lookup?id=527563481");
	WinClient.SetRequireValidSslCertificates(false);
	WinClient.SendHttpRequest(L"GET");
	wstring httpResponseContent = WinClient.GetResponseContent();
	MessageBoxW(NULL,httpResponseContent.c_str(),L"http://www.baidu.com",MB_OK);

	return 0;
}

