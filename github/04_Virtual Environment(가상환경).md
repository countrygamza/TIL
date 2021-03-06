# 가상환경(Virtual Environment)

## 가상환경이란?

> 자신이 원하는 Python  환경 구축을 위해 필요한 모듈만을 모아놓은 것.
>
> 각각의 가상환경은 독립적이어서 서로 다른 가상환경에 설치된 모듈들의 영향을 받지 않는다.



## 가상환경을 쓰는 이유는?

>  라이브러리를 설치하면 기본적으로 컴퓨터에 내에 전역적으로 적용되는데, 프로젝트 별로 각각 다른 버전의 라이브러리를 사용해야 하는 경우가 생긴다. 그때그때 하려는 작업과 맞는 버전의 라이브러리를 쓰기 위해 가상환경에서 작업한다.



## 가상환경 생성 방법

```bash
$ python -m venv venv : 가상환경 생성
$ source venv/Scripts/activate : 가상환경에 들어감
$ deactivate : 가상환경에서 나감
```

이런 식으로 할 경우 가상환경에 들어갈 때 마다 새로 지정해줘야 한다는 단점이 있다.



그래서 바로 접속할 수 있도록 설정하는 방법이 있다.

```bash
$ vi ~/.bashrc
-> i
-> alias activate="source venv/Scripts/activate"    # alias 이용해서 별명 붙여주는 것?
-> esc연타 후 :wq

```

`bash`를 껐다 켠 후, 만들었던 `venv`가 있는 폴더로 경로를 바꾼 후

```bash
$ source ~/.bashrc
$ activate
```

이렇게 하면 바로 가상환경에 접속된다. 즉, `venv` 폴더에 있는 파이썬을 사용하는 것과도 같다.

로컬과 다른 파이썬 버전은 물론이고, 다른 버전의 라이브러리들도 사용할 수 있다.



---

### `git ignore`

가상환경에 있는 라이브러리는 보통 많이 다운받게 되므로, 이를 `github`에 올리려면 용량이 너무 크다.

그래서 가상환경에 있는 라이브러리를 깃에 올리지 않도록 제외시키는 방법이 있다.



`gitignore.io` 사이트에 들어가서` python`, ` venv`, `flask` 이 3개를 치고 생성버튼을 누른다.

나오는 코드를 `전체복사`한 뒤 다시 `bash`로 온다.

```bash
$ vi .gitignore
-> shift + Insert  # 붙여넣기 in bash
-> esc 연타 후 :wq
```



---

### `pip freeze`

다른 사람들과 협업 시, 내가 어떤 버전의 라이브러리를 썼는지 알려줄 수 있다.



가상환경에서 다음의 코드를 치면 내가 깔았던 라이브러리 및 그 버전들이 적혀있는 txt파일이 하나 생긴다.

```bash
$ pip freeze > requirements.txt
```



이를 코워커와 공유한다. 코워커가 이 파일을 자신의 가상환경 폴더에 넣고

```bash
$ pip install -r requirements.txt
```

이 코드를 치면 바로 내가 썼던 라이브러리 버전들이 깔린다.