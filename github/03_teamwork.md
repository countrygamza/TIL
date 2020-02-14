# Fork와 Pull Request

## Fork

> 'Fork'는 타인의 Github repository를 내 계정으로 복제하는 기능



가져올 repository를 고른 후 우측 상단의 Fork를 클릭하면 repository 째로 내 github에서 볼 수 있다.



fork한 repository는 원본(original repository)과 연결되어 있으므로, 원본에 어떤 변화가 생기면 fetch나 rebase를 통해 나의 forked repository에도 반영할 수 있다.



---

## Pull request

> 'Pull request'는 추가적으로 수정한 사항을 original repository에 적용하고 싶을 때 사용하는 기능  (단, original repository에 pull request가 허용돼 있을 시만 가능)



### `pull request` 하는 방법 

- fork하여 내 github으로 가져온 repository에 변경사항을 적용한 후 Push한다.
- 원래 저장소(original repository)에 내 저장소에 있는 브랜치를 `pull request`(repository 상단 가운데) 한다.
- 내가 만든 코드가 관리자로부터 승인이 되면 해당 저장소에 commit, merge 된다.
- `pull request` 하기 전까지는 내 Github 에 있는 forked repository에만 change가 적용된다.