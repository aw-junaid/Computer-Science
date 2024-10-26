Comprehensive GitHub cheat sheet covering essential Git and GitHub commands, their usage, and explanations for each. These commands will help you manage Git repositories effectively, whether you're working alone or collaborating on GitHub.

---

## **Basic Git Commands**

### 1. **Setup & Configuration**

```bash
# Set up your Git user name
git config --global user.name "Your Name"

# Set up your Git email
git config --global user.email "your-email@example.com"

# Check the configuration settings
git config --list
```

*Explanation*: These commands configure your Git username and email, which appear in commit messages. The `--global` flag applies these settings across all repositories on your machine.

---

### 2. **Creating a New Repository**

```bash
# Initialize a new Git repository in the current directory
git init
```

*Explanation*: This command initializes a new Git repository, creating a `.git` directory. Use this in a new project folder to start tracking changes.

---

### 3. **Cloning an Existing Repository**

```bash
# Clone a GitHub repository (replace URL with your repository URL)
git clone https://github.com/user/repository.git
```

*Explanation*: `git clone` copies an existing repository from GitHub (or another Git server) to your local machine.

---

## **Basic Workflow Commands**

### 4. **Checking Repository Status**

```bash
# View changes not yet staged for commit
git status
```

*Explanation*: This command shows files that have been modified, added, or deleted in the repository. It helps you keep track of uncommitted changes.

---

### 5. **Adding Files to Staging Area**

```bash
# Stage all changes
git add .

# Stage a specific file
git add filename
```

*Explanation*: `git add` stages changes, marking them for inclusion in the next commit. You can stage individual files or all changes at once.

---

### 6. **Committing Changes**

```bash
# Commit staged changes with a message
git commit -m "Commit message here"
```

*Explanation*: Commits all staged changes to the repository with a description. Use descriptive messages to explain the changes.

---

### 7. **Pushing Changes to Remote Repository**

```bash
# Push commits to the default remote branch (usually `main` or `master`)
git push origin main
```

*Explanation*: `git push` uploads your local commits to the GitHub repository. Replace `main` with your branch name if different.

---

## **Branching & Merging**

### 8. **Creating a New Branch**

```bash
# Create a new branch
git branch branch-name

# Switch to the new branch
git checkout branch-name

# Create and switch to the branch in one command (modern Git)
git switch -c branch-name
```

*Explanation*: Branches allow you to work on different features or bug fixes independently. Use `git branch` to create a branch and `git checkout` to switch to it.

---

### 9. **Viewing Branches**

```bash
# List all branches
git branch

# List remote branches
git branch -r
```

*Explanation*: `git branch` lists branches, highlighting the current branch. `-r` displays remote branches.

---

### 10. **Merging Branches**

```bash
# Merge a branch into the current branch
git merge branch-name
```

*Explanation*: Merging incorporates changes from one branch into another, usually to combine feature work or fix bugs. Be sure to resolve any conflicts.

---

### 11. **Deleting a Branch**

```bash
# Delete a local branch
git branch -d branch-name

# Delete a remote branch
git push origin --delete branch-name
```

*Explanation*: Deleting branches after merging helps keep the repository clean. Use `-d` for local branches and `--delete` for remote branches.

---

## **Remote Repositories**

### 12. **Adding a Remote Repository**

```bash
# Add a new remote repository
git remote add origin https://github.com/user/repository.git
```

*Explanation*: This command connects a local repository to a remote GitHub repository, allowing you to push and pull changes.

---

### 13. **Viewing Remote Repositories**

```bash
# List all remotes
git remote -v
```

*Explanation*: Lists remote repositories linked to the local repo. Each remote has a name (e.g., `origin`) and URL.

---

### 14. **Fetching & Pulling Changes**

```bash
# Fetch updates from the remote repository without merging
git fetch origin

# Pull updates from the remote and merge with the local branch
git pull origin branch-name
```

*Explanation*: `git fetch` retrieves changes without merging, while `git pull` fetches and merges changes into the current branch.

---

## **Undoing Changes**

### 15. **Discarding Changes**

```bash
# Discard changes in a specific file
git checkout -- filename

# Discard all changes in the working directory
git reset --hard
```

*Explanation*: These commands revert uncommitted changes. Use with caution, as changes will be lost.

---

### 16. **Unstaging Changes**

```bash
# Unstage a file
git reset filename
```

*Explanation*: Moves a file from the staging area back to the working directory, removing it from the next commit.

---

### 17. **Amending the Last Commit**

```bash
# Amend the last commit with new changes
git commit --amend -m "Updated commit message"
```

*Explanation*: Allows you to edit the last commit’s message or add new changes without creating a new commit.

---

## **Collaboration Commands**

### 18. **Viewing Commit History**

```bash
# View commit history
git log

# View a one-line summary of commits
git log --oneline
```

*Explanation*: `git log` shows the commit history, while `--oneline` condenses it. Useful for tracking past changes.

---

### 19. **Rebasing Branches**

```bash
# Rebase the current branch onto another branch
git rebase branch-name
```

*Explanation*: Rebasing rewrites commit history, incorporating changes from one branch into another. Be careful with rebasing shared branches.

---

### 20. **Creating a Pull Request (PR)**

1. **Push your branch** to GitHub.
2. Go to the GitHub repository.
3. Click **"New Pull Request"** and select the branches to merge.
4. Provide a title and description, then **submit the pull request**.

*Explanation*: PRs let you propose changes for review before merging, essential for collaborative projects.

---

## **Advanced Commands**

### 21. **Stashing Changes**

```bash
# Stash current changes
git stash

# Apply the most recent stash
git stash apply

# List stashes
git stash list
```

*Explanation*: Stashing saves uncommitted changes without committing, allowing you to switch branches or temporarily discard changes.

---

### 22. **Cherry-Picking Commits**

```bash
# Apply a specific commit from another branch
git cherry-pick commit-hash
```

*Explanation*: Cherry-picking applies specific commits from another branch into the current branch. Useful for selectively merging changes.

---

### 23. **Tagging Releases**

```bash
# Create a new tag
git tag -a v1.0 -m "Version 1.0 release"

# Push tags to remote
git push origin --tags
```

*Explanation*: Tags mark specific commits, often used for release versions. Annotated tags (`-a`) include descriptions.

---

### 24. **Resetting Commits**

```bash
# Reset to a specific commit, discarding commits after it
git reset --hard commit-hash
```

*Explanation*: `git reset` undoes commits. Use `--hard` to discard all changes after the specified commit, or `--soft` to keep them in the staging area.

---

### 25. **Viewing Diffs**

```bash
# View differences in modified files
git diff

# View differences in staged files
git diff --staged
```

*Explanation*: Shows changes between files in your working directory and the repository’s history, helping track uncommitted edits.

---

### 26. **Squashing Commits**

1. Run `git rebase -i HEAD~n` (replace `n` with the number of commits to combine).
2. In the interactive prompt, mark the commits to **squash** or **fix**.

*Explanation*: Squashing combines multiple commits into one, which simplifies history. Useful for cleaning up commit logs before merging.

---

This cheat sheet covers a wide range of Git and GitHub commands, from setup to advanced features. Practice these to boost your Git skills and master version control!
