<#
=============================================================
 iot-summer-school-2026 — Full Setup & Publish Script (PowerShell)
=============================================================
 This script documents EVERY command used to build, commit,
 branch, and publish this repository to GitHub, in the exact
 order they were run. Run sections individually (recommended)
 rather than the whole file at once, since some steps assume
 the previous step already succeeded.

 Prerequisites:
   - Git installed and configured (git config --global user.name / user.email)
   - GitHub CLI installed and authenticated (gh auth login)   [optional, for issues/PR]
   - An empty GitHub repository already created:
       https://github.com/your-username/iot-summer-school-2026
=============================================================
#>

# -------------------------------------------------------------
# 1. REPOSITORY & FOLDER CREATION
# -------------------------------------------------------------
New-Item -ItemType Directory -Path "iot-summer-school-2026" | Out-Null
Set-Location -Path "iot-summer-school-2026"

New-Item -ItemType Directory -Path ".github\workflows" -Force | Out-Null
New-Item -ItemType Directory -Path "scripts" -Force | Out-Null
New-Item -ItemType Directory -Path "week1\led_blink\versions" -Force | Out-Null
New-Item -ItemType Directory -Path "week2" -Force | Out-Null
New-Item -ItemType Directory -Path "week3" -Force | Out-Null
New-Item -ItemType Directory -Path "final-project" -Force | Out-Null
New-Item -ItemType Directory -Path "theory" -Force | Out-Null
New-Item -ItemType Directory -Path "docs" -Force | Out-Null

# (At this point, copy/create all project files into the folders above.)

# -------------------------------------------------------------
# 2. GIT INITIALIZATION
# -------------------------------------------------------------
git init
git branch -M main
git remote add origin https://github.com/your-username/iot-summer-school-2026.git

# -------------------------------------------------------------
# 3. INITIAL COMMIT — README, LICENSE, .gitignore
# -------------------------------------------------------------
git add README.md LICENSE .gitignore
git commit -m "docs: initialize repository"
git push -u origin main

# -------------------------------------------------------------
# 4. CREATE THE `dev` INTEGRATION BRANCH
# -------------------------------------------------------------
git checkout -b dev
git push -u origin dev

# -------------------------------------------------------------
# 5. Q2 — BASELINE LED BLINK SKETCH
# -------------------------------------------------------------
git add week1/led_blink/led_blink.ino
git commit -m "feat: add LED blink starter code"
git push origin dev

# -------------------------------------------------------------
# 6. Q4 — FOUR PROGRESSIVE SKETCH VERSIONS
# -------------------------------------------------------------
git add week1/led_blink/versions/v1.0_basic_blink.ino
git commit -m "feat: add v1.0 basic 500ms blink sketch"

git add week1/led_blink/versions/v1.1_serial_blink_counter.ino
git commit -m "feat: add serial blink counter"

git add week1/led_blink/versions/v1.2_potentiometer_control.ino
git commit -m "feat: add potentiometer speed control"

git add week1/led_blink/versions/v1.3_professional_final.ino
git commit -m "feat: add professional final blink sketch (v1.3)"

git push origin dev

# -------------------------------------------------------------
# 7. Q7 — MODIFIED BLINK PATTERN (feature branch + PR flow)
# -------------------------------------------------------------
git checkout -b feature/blink-modified dev
git add week1/blink_modified.ino
git commit -m "feat: add modified blink pattern (3 fast blinks + 2s pause)

Fixes #1"
git push -u origin feature/blink-modified

# --> Open a Pull Request on GitHub: feature/blink-modified -> dev
#     (see docs/github-issues-and-pr.md for title/description/checklist)

# After PR review & approval, merge locally (or merge via GitHub UI):
git checkout dev
git pull origin dev
git merge feature/blink-modified
git push origin dev
git branch -d feature/blink-modified
git push origin --delete feature/blink-modified

# -------------------------------------------------------------
# 8. Q5 — PROJECT DOCUMENTATION FOR led_blink
# -------------------------------------------------------------
git add week1/led_blink/README.md
git commit -m "docs: add project documentation"
git push origin dev

# -------------------------------------------------------------
# 9. Q3, Q9, Q10, Q6/Q7 DOCS — NOTES + THEORY + ISSUE/PR CONTENT
# -------------------------------------------------------------
git add notes.md theory/q9.md theory/q10.md docs/github-issues-and-pr.md
git commit -m "docs: add branching notes, git theory, and issue/PR documentation"
git push origin dev

# -------------------------------------------------------------
# 10. Q8 — CI: GITHUB ACTIONS WORKFLOW + PYTHON SCRIPT
# -------------------------------------------------------------
git add scripts/count_ino.py .github/workflows/lint.yml
git commit -m "ci: add GitHub Actions workflow"
git push origin dev

# -------------------------------------------------------------
# 11. SCAFFOLD FUTURE WEEKS
# -------------------------------------------------------------
git add week2/.gitkeep week3/.gitkeep final-project/.gitkeep
git commit -m "chore: scaffold week2, week3, and final-project folders"
git push origin dev

# -------------------------------------------------------------
# 12. FEATURE BRANCHES FOR FUTURE MODULES (per notes.md)
# -------------------------------------------------------------
git checkout -b sensor-module dev
git push -u origin sensor-module

git checkout -b wireless-module dev
git push -u origin wireless-module

# -------------------------------------------------------------
# 13. MERGE `dev` INTO `main` (RELEASE WEEK 1)
# -------------------------------------------------------------
git checkout main
git pull origin main
git merge dev
git push origin main

# -------------------------------------------------------------
# 14. GITHUB ISSUES + MILESTONE (requires GitHub CLI: gh auth login)
# -------------------------------------------------------------
gh milestone create "Week 1 Completion" --repo your-username/iot-summer-school-2026

gh issue create `
  --repo your-username/iot-summer-school-2026 `
  --title "Create basic LED blink sketch" `
  --body "See docs/github-issues-and-pr.md for full description." `
  --label "enhancement,week-1" `
  --milestone "Week 1 Completion"

gh issue create `
  --repo your-username/iot-summer-school-2026 `
  --title "Add Serial Monitor blink counter" `
  --body "See docs/github-issues-and-pr.md for full description." `
  --label "enhancement,week-1" `
  --milestone "Week 1 Completion"

gh issue create `
  --repo your-username/iot-summer-school-2026 `
  --title "Add potentiometer-controlled blink speed" `
  --body "See docs/github-issues-and-pr.md for full description." `
  --label "enhancement,hardware,week-1" `
  --milestone "Week 1 Completion"

# -------------------------------------------------------------
# 15. VERIFY CI RAN SUCCESSFULLY
# -------------------------------------------------------------
gh run list --repo your-username/iot-summer-school-2026 --limit 5

# =============================================================
# DONE. Repository is fully published with:
#   - main + dev + sensor-module + wireless-module branches
#   - Conventional Commit history
#   - A merged PR (feature/blink-modified -> dev)
#   - 3 GitHub Issues under the "Week 1 Completion" milestone
#   - A passing GitHub Actions CI workflow
# =============================================================
