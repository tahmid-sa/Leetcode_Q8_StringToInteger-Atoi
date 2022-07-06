git init -b main
git add .
git commit -m "Adding files to github"

git pull $1 main --allow-unrelated-histories
git push $1 main