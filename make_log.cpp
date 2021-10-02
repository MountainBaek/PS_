#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>
using namespace std;
/*
192.168.2.20 - - [28/Jul/2006:10:27:10 -0300] "GET /cgi-bin/try/ HTTP/1.0" 200 3395
200 : 성공
400 : 실패
500 : 서버응답실패
*/
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	srand((unsigned int)time(0));
	string ipstart;
	cin >> ipstart;
	
	for (int i = 0; i < 50; i++) {
		int ip = (rand() % 256);
		int day = 1+(rand() % 7);
		int hour = (rand() % 24);
		int min = (rand() % 60);
		int sec = (rand() % 60);
		int data = (rand() % 10000);
		int response;
		while (1) {
			response = (rand() % 501);
			if (response == 200 || response == 400 || response == 500) {
				break;
			}
		}
		if (hour < 10) {
			if (min < 10) {
				if (sec < 10) {
					cout << ipstart <<"."<< ip << ".0 - - [" << day << "/Oct/2018:0" << hour << ":0" << min << ":0" << sec << " - 0300] \"\GET " << "URL 경로" << "HTTP/1.0\"\ " << response << " " << data << '\n';
			
				}
				else {
					cout << ipstart << "." << ip << ".0 - - [" << day << "/Oct/2018:0" << hour << ":0" << min << ":" << sec << " - 0300] \"\GET " << "URL 경로" << "HTTP/1.0\"\ " << response << " " << data << '\n';
					}
			}
			else {
				if (sec < 10) {
					cout << ipstart << "." << ip << ".0 - - [" << day << "/Oct/2018:0" << hour << ":" << min << ":0" << sec << " - 0300] \"\GET " << "URL 경로" << "HTTP/1.0\"\ " << response << " " << data << '\n';
					}
				else {
					cout << ipstart << "." << ip << ".0 - - [" << day << "/Oct/2018:0" << hour << ":" << min << ":" << sec << " - 0300] \"\GET " << "URL 경로" << "HTTP/1.0\"\ " << response << " " << data << '\n';
					}
		
			}
		}
		else {
			if (min < 10) {
				if (sec < 10) {
					cout << ipstart << "." << ip << ".0 - - [" << day << "/Oct/2018:" << hour << ":0" << min << ":0" << sec << " - 0300] \"\GET " << "URL 경로" << "HTTP/1.0\"\ " << response << " " << data << '\n';
						}
				else {
					cout << ipstart << "." << ip << ".0 - - [" << day << "/Oct/2018:" << hour << ":0" << min << ":" << sec << " - 0300] \"\GET " << "URL 경로" << "HTTP/1.0\"\ " << response << " " << data << '\n';
					}
			}
			else {
				if (sec < 10) {
					cout << ipstart << "." << ip << ".0 - - [" << day << "/Oct/2018:" << hour << ":" << min << ":0" << sec << " - 0300] \"\GET " << "URL 경로" << "HTTP/1.0\"\ " << response << " " << data << '\n';
						}
				else {
					cout << ipstart << "." << ip << ".0 - - [" << day << "/Oct/2018:" << hour << ":" << min << ":" << sec << " - 0300] \"\GET " << "URL 경로" << "HTTP/1.0\"\ " << response << " " << data << '\n';
						}

			}
		}

	}

}
