12/11

cd ~ : 홈디렉토리
code . : 현재 폴더를 기준으로 visual studio code(editor) 가 열린다.
editor에서 저장 ctrl+S
사진대에 올려둔 것 빼고싶다면? git rm --cached <file>...

$ git commit --amend
staging area에는 a가 올라와있는데 commit은 b로 했을때? commit을 다시 a로 하고 싶으면? 정보가 막 뜬다.

esc 빠져나오기
i로 끼워넣기 한 다음에 b를 a로 바꾸고 
:q 그냥나가기
:wq 저장하고 나가기
git log --oneline 했을 때 노란 표시: 커밋고유이름

git reset --hard 커밋고유이름 : 커밋 삭제??????
git checkout 커밋고유이름: 어느 특정 스냅샷을 본다. 체크한다. 찍어놓은 스냅샷 단위로 
특정 스냅샷으로 간다. 작업환경을 여러 커밋들 중 특정 상태로 가리키게...  이때 가리키는 포인터의 이름이 head  돌아가는 게 아니라 체크한다. 다른 커밋들의 역사는 없어지지 않는다. 
checkout 상태에서 뭔가를 바꿔놓으면 checkout master했을 때 뜨는 branch가 생긴다.  
master의 working directory에서는 그 바뀐 작업들이 없어져있다.

pull push는 한사람이 작업을 끝내야 다른사람이 이어서할수있다는 단점. 

현실; master

git branch 브랜치이름
git checkout 브랜치이름: (master) -> (test)
브랜치 움직일 때; git checkout

Head가 test로 바뀌어있을 것. head가 test(가상세계)일때 했던 작업은 별다른 작업 없이 head를 master로 돌리면 없어진다.

브랜치 지우는법? git branch -D or -d 브랜치이름
(D는 강제성. D로하는 이유는 merge되기 전이라 잔존하는 팩터들이 남아있는데 그냥 강제로 지우려는 것이므로!)

branch를 만들면서 이동
git checkout -b new : new라는 브랜치를 만든 뒤 이동

합치는 법?
중심이 되는 브랜치로 이동 git checkout master
git merge 합칠브랜치이름
깔끔하게 ㅏㅂ쳐졌다면 텅빈 브랜치는 지운다.  ---> master에 변화가 없을 때 기준

만약 합칠 때 양쪽에, 즉 master에도 변화가 있다면?
git merge 합칠브랜치이름 : 이상한화면 나올것...
esc / :wq
git log --oneline --graph 하면 그래프로도 나온다.
----> 또 어떤 ㅓㅅ을 남길지 선택하라고 나온다. Accept both change!
merge된 파일 add, commit


pip install requests
pip list : 어떤 것들이 설치되어있는지

bs4: 컨텐츠들을 해석해서 예쁘게 가져와주는 역할 (Parsing)


상위폴더 TIL에 .git(git init)이 이미 돼있으면 하위폴더에서 git init을 또하면 push가 안된다. 다른 폴더에 만들어줘야 한다.