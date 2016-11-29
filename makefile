commit:
	git config credential.helper store
	git init
	git add .
	git commit -m "Commit"
	git remote add origins https://github.com/Ghui/mdl-animation.git
	git remote -v
	git push origins master

