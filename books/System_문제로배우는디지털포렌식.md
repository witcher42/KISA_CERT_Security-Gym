### MBR
- 디스크의 시작점의 첫번째 섹터에 있는 영역으로 OS를 부팅해주는 역할을 한다  
- GUID로 불리는 하드디스크의 고유값이 저장되어 있다  
### MFT
- 파일 디렉터리의 속성정보를 구분하는 NTFS 파일시스템의 메타파일  
- $MFT
  -      MFT를 담은 파일  
- $LogFile  
  -      트랜잭션 저널 기록을 저장  
- $Volume  
  -      볼륨 정보 저장  
- $Boot  
  -      부트 레코드 영역 정보 저장  
- $UsrJrnl  
  -      파일이나 디렉터리 변경사항에 대한 정보 저장
  -      $Max : 변경로그의 기본 메타 데이터 저장  
  -      $J   : 실제 변경 레코드를 저장  
### 주요로그  
- /var/log/secure
  - 텔넷, ssh 등 원격 접속에 대한 기록  
- /var/dmesg  
  - 부팅 당시의 메시지 저장  
- /var/log/messages  
  - 리눅스 커널로그  
### 아티팩트  
- 사용자가 컴퓨터를 사용하면서 남긴 흔적  
- 캐쉬, 히스토리 등  
### 프리페치  
- 윈도우 메모리 관리정책   
### System Call  
- 커널함수가 필요할때 응용프로그램에서 호출할수 있도록 하는것  
- 일반적으로 하드웨어 운영체제는 운영프로그램 실행도중에 운영프로그램이 커널에 접근하지 못하도록 막는 보안기능이 있다  
### HKCU₩Software₩Microsoft₩Windows₩CurrentVersion ₩Explorer₩RecentDocs  
- 윈도우 탐색기를 통해 실행하는 목록과 최근에 open한 파일의 폴더 목록을 유지한다  
- 파일명을 바이너리 형태로 기록한다  
### HKCU₩Software₩Microsoft₩Windows₩CurrentVersion ₩Explorer₩RunMRU
- 실행창에서 실행한 명령의 목록을 기록한다  
  - C:\Windows\System32\config\SAM : 로컬 계정 정보와 그룹 정보 저장  

