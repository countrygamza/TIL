# Github Push & Pull

## 초기설정

### (1) `git init`

> Git으로 프로젝트 관리 시작
>
> bash에서 git과 연동될 파일 설정
>
> 초기설정으로 한 번 연결되면 계속 연결되어 있다.

### (2) `git remote`

> 원격저장소 정보 추가
>
> local 폴더와 github의 repository를 연결



---

## Push: `bash`에서 `github`로 업로드

### (1) `git add`

- staging area에 올려준다.

  ```bash
  $ git add homework.txt
  ```

- 이때 git status로 확인해보면 상태가 바뀌어있다. 

  ``` bash
  $ git status
  On branch master
  Your branch is up to date with 'origin/master'.
  
  Changes to be committed:
    (use "git restore --staged <file>..." to unstage)
          new file:   homework.txt
  ```

### (2) `git commit`

- 현재 상태에 대한 스냅샷을 찍어서 버전관리를 진행한다.

  ```bash
  $ git commit -m "Add homework.txt"  
  
  # -m을 넣지 않으면 다른 페이지로 연결되어 번거로워진다.
  # 메세지는 최대한 간결하게 어떤 작업을 했는지 알 수 있도록 쓴다.
  ```

### (3) `git log`

- 만들어진 commit 확인하기

  ```bash
  $ git log
  $ git log --oneline   # 한 줄로 간단하게 볼 수 있다.
  $ git log -1          # 가장 최근에 만든 한 개의 commit을 볼 수 있다.
  ```

### (4) `git push`

- Github에 업로드하기

  ```bash
  $ git push origin master   # origin은 원격저장소 이름
  ```



---

## Pull: github에서 bash로 파일 내려받기

- github repository 안의 파일을 local computer로 복사해준다.

### (1) `git clone`

- 최초로 파일을 가져올 때는 git clone으로 repository 자체를 복사해준다.

- `git clone`을 하면 자동으로 `git init`설정이 완료되므로 따로 할 필요 없다.

- 그러나 repository 접근성에 따라 권한이 다르다.

  - 접근 허용된 repository이면 허용된 주소로 push & pull 가능
  - 접근 허용되지 않으면 pull만 가능

  ```bash
  $ git clone https://github.com/countrygamza/TIL.git # URL주소
  ```

### (2) `git pull`

- 한 번 `git clone`을 통해 github repository 파일을 받아왔다면, 그 이후부터는 `git pull`을 통해 복사한다.

- `git status`를 쳐봤을 때 working tree가 clean한 상태여야만 pull이 가능하다.

  ```bash
  $ git pull origin master
  ```



---

## Github와 bash의 충돌

### 1) Github와 Local에서 서로 다른 파일이 존재할 때

Github에는 trash.txt 파일이, local에는 junk.txt 파일이 존재한다고 가정했을 때, local에서 junk.txt을 trash.txt 파일로 착각하여 `git pull` 명령어를 수행시키면 local은 junk.txt 와 trash.txt 파일 2개가 생성된다.

=> 이런 경우 모두 남기는 방식으로 충돌은 자동해결된다.

### 2) Github와 Local에서 같은 파일, 다른 내용이 존재할 때

GIthub와 Local에 모두 dump.txt 파일이 존재하지만 Github에서는 ABC로 내용이 저장되어 있고, Local에서는 DEF로 내용이 저장되어 있다.

이런 경우의 PULL은 Local의 한 파일에 ABC, DEF 두 가지가 충돌되며 에러발생

- 두 가지 내용을 어떻게 저장할 것인지 선택해야 한다.

  - visual studio code에서 선택

    ```
    $ code .
    ```

  - 메모장에서 선택해서 저장

    - `<> `와 `hash 태그` 지우고 남기고 싶은 `content`만 표시한 후 저장

- 이후에 `git add`와 `git commit -m " "` `git push` 단계를 거쳐서 github에 업로드

## 

## stash

## checkout

git checkout <16진수ID>

git checkout master

그 외 기억하고 싶은 명령어

- `git log #--online` :commit들의 역사

- q : 나가기 , qw : 저장하고 나가기
- cat 파일명 : 내용출력 cat quiz.txt: quiz.txt의 파일내용을 볼 수 있다.



### `pull` 상황에서 conflict이 일어나면?

****





**merge: Git 충돌 (refusing to merge unrelated histories) 해결 **

서로 다른 코드간의 충돌 발생 시, 충돌되는 두 코드 중 하나를 선택해서 이용하는 방법

```
$ git commit -m "Resolve Conflict" 
```

**`stash`: Git 충돌 (refusing to merge unrelated histories) 해결 **

지금의 코드를 만들어내긴 했는데 뭔가 오류가 생기게 됩니다. 하지만 그렇다고 코드를 날려버리기엔 아까울 때, **백업 및 책갈피 개념**으로서 이 명령어를 쓰면 딱 좋을겁니다.



git push -u origin master: 

git stash: 중간에 잠시 임시저장해놓는 것
git checkout: 체크를 하다. 상태를 보러가고싶다. 되돌리기. 이전 시점으로 돌아가자.
git checkout master: 체크아웃하기 전으로 돌아온다.

merge 화면 나오면 esc 세 번 누르기, 한영키 영어로 바꾸기,

같은 파일인데 내용물이 다를 경우? github과 local에서 따로 같은 파일을 작업했을 경우? 니가 선택하라고 나온다.
---> 갈등 해결(수정된 사항 두 개 다 반영)됐을 땐
---> add & commit -m "Resolve conflict"

자동으로 합칠 때는 언제???
chatbot.py.....
pull request