# Github TIL

## 1. TIL?

> - TIL은 **T**oday **I** **L**earned의 줄임말로 개발자 사이에서 매일 자신이 학습한 내용을 commit(기록)하는 것
> - github, bitbuckets, gitlab과 같은 원격 저장소에서 제공하는 1commit-1grass의 흥미 요소 제공

 

---

## 2. TIL 세팅

### (1) `pwd`

- 현재 위치 확인

- 파일을 생성하기 전 항상 최상위 폴더인지 확인한다.

  ```bash
  $ pwd
  /c/Users/
  ```

### (2) `cd`

- 원하는 위치로 이동

  ```bash
  $ cd student
  $ cd ~  # 최상단폴더로 이동하기
  $ cd .. # 한 단계 상위폴더로 이동하기
  ```

### (3) `mkdir`

- 새 폴더 만들기

  ```bash
  $ mkdir TIL  
  # student에 TIL이라는 폴더 새로 만들기
  # 해당 폴더는 최상단에 생성해야 함
  ```

### (4) `touch`

- 새 파일 생성

- 폴더는 mkdir, 파일은 touch

  ```bash
  $ touch homework.txt
  ```

### (5) `git init`

- 해당 폴더를 git으로 프로젝트 관리하기 시작한다.

- bash에서 git과 연동될 폴더 설정 - 최상위 폴더는 안 된다.

- 초기 설정으로 한 번 연결되면 계속 연결되어 있다.

- 삭제: 해당 파일에서 rm r .git 명령어로 .git 숨김폴더 삭제

  ```bash
  $ git init # git으로 관리하는 파일을 다룰 것이다.
  ```

### (6) `git add`

- 현재 코드 상태의 스냅샷을 찍기 위한 파일 선택 (==Staging Area에 파일 추가)

  ```bash
  $ git add 파일이름  # .은 모든 변경사항을 staging area로 올림
  ```

### (7) `git commit`

- 버전관리를 위한 스냅샷 저장(save)

- 현재 상태에 대한 스냅샷을 `commit`하여, 버전관리를 진행한다.

  ```bash
  $ git commit -m "커밋메시지"
  ```

### (8) `git remote`

- 폴더를 업로드할 원격 저장소(repository)의 정보 추가

- Github에서 원격(remote) 저장소(repository)를 생성하고 TIL 폴더와 연결한다.

- 새로운 원격 저장소가 추가될 때만 입력한다.

  ```bash
  $ git remote add 원격저장소주소
  $ git remote add origin # origin은 최초 원격저장소
  ```

### (9) `git push`

- 최종적으로 Github 원격저장소에 push한다.

  ```bash
  $ git push origin master
  ```

### (10) 그 외 명령어

- 현재 git의 상태를 조회:  `git status`

  파일이 잘 만들어졌는지 or 수정되었는지 확인

  ```bash
  $ git status
  On branch master
  Your branch is up to date with 'origin/master'.
  
  Untracked files:
    (use "git add <file>..." to include in what will be committed)
          homework.txt
  
  nothing added to commit but untracked files present (use "git add" to track)
  ```

- 버전 관리이력을 조회: `git log`

  ```bash
  $ git log
  commit 5653652310c4566fb73788d22f630a8d137df028 (HEAD -> master, origin/master)
  Merge: 4b9bd79 93f020b
  Author: Sehee Han <ttehees2@gmail.com>
  Date:   Tue Dec 10 17:38:06 2019 +0900
  
      Resolve conflict
  ```

- 해당 위치에 생성돼 있는 자료 리스트 확인: `ls`

  ```bash
  $ ls
  00_markdown_basic.md
  ```
  
- 달라진 내용 확인: `git diff`

  ```bash
  $ git diff
  ```
  
- git 설정(user.name & user.email): **최초 1회 설정**

  ```bash
  $ git config --global user.name "John Kang"
  $ git config --global user.email "hphk.john@gmail.com"
  ```



---

## 3. `README.md`

> 원격(remote)저장소(repository)에 대한 정보를 기록하는 마크다운 문서. 일반적으로 해당 프로젝트를 사용하기 위한 방법 등을 기재한다.

### (1) `README.md` 파일 생성 

- `README.md`파일을 `TIL`폴더(최상단)에 생성한다. 이름은 반드시 README.md로 설정한다.

  ```bash
  $ touch README.md
  ```

### (2) (자신만의) TIL 원칙에 대한 간단한 내용 추가

- 마크다운 작성법 pdf에서 배우고 실습한 내용을 토대로 `README.md` 파일을 작성한다.
- 형식은 자유롭게 작성하되 마크다운 문법(의미론적)을 지켜서 작성한다.

### (3) 저장 후 버전관리: `add`, `commit`, `push`

- 작성이 완료되면 아래의 명령어를 통해 commit 이력을 남기고 원격 저장소로 push한다.

  ```bash
  $ git add README.md
  $ git commit -m "add README.md"
  $ git push origin master
  ```



---

## 4. 추가 학습내용 관리

### (1) 추가 내용 관리

- `TIL` 폴더 내에서 학습을 원하는 내용의 폴더를 생성하고 파일들을 생성한 후 작업을 진행한다.

  ```bash
  $ mkdir python
  ```

### (2) 변경사항을 저장하고, 원격저장소로 옮긴다.

- 업데이트가 완료되면 아래의 명령어를 통해 commit 이력을 남기고 원격저장소로 push한다.

  ```bash
  $ git add .
  $ git commit -m "학습 내용 추가"
  $ git push origin master
  ```


