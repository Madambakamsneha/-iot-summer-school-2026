<div align="center">

# 🌐 IoT Summer School 2026

### Embedded Systems & IoT — Module 1 Coursework Repository

**Student Name:** `[Your Name]`
**Roll Number:** `[Your Roll Number]`

This repository documents my Week 1 embedded systems coursework, covering Arduino
fundamentals, Git version control, and CI automation. It tracks the full
progression from a basic LED blink sketch to a documented, sensor-driven build.

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Lint Workflow](https://img.shields.io/badge/CI-GitHub%20Actions-blue?logo=githubactions&logoColor=white)
![Status](https://img.shields.io/badge/Status-In%20Progress-orange)

</div>

---

## 📌 Objectives

- 🔌 Understand Arduino digital/analog I/O through hands-on sketches
- 🌿 Practice a realistic Git branching workflow (`main`, `dev`, feature branches)
- 📝 Write clear, professional technical documentation
- ⚙️ Automate repository checks with GitHub Actions
- 🧩 Build toward a final IoT integration project

---

## 📁 Folder Structure

```
iot-summer-school-2026/
│
├── .github/
│   └── workflows/
│       └── lint.yml              # CI workflow — counts .ino files on push
│
├── scripts/
│   └── count_ino.py              # Arduino sketch counter used by CI
│
├── week1/
│   ├── led_blink/
│   │   ├── led_blink.ino         # Baseline LED blink sketch
│   │   ├── README.md             # Circuit + usage documentation
│   │   └── versions/             # Iterative sketch versions (v1.0 – v1.3)
│   └── blink_modified.ino        # 3 fast blinks + 2s pause variant
│
├── week2/                        # Reserved for upcoming coursework
├── week3/                        # Reserved for upcoming coursework
├── final-project/                # Reserved for capstone IoT project
│
├── theory/
│   ├── q9.md                     # git clone vs fetch vs pull
│   └── q10.md                    # .gitignore deep dive
│
├── docs/
│   ├── github-issues.md          # Week 1 issue tracker content
│   ├── pull-request-week1.md     # PR description + checklist
│   ├── commit-log.md             # Full Conventional Commits history
│   └── setup-commands.md         # PowerShell setup/push commands
│
├── README.md
├── LICENSE
├── .gitignore
└── notes.md                      # Git branching strategy notes
```

---

## 🛠️ Technologies Used

| Technology            | Purpose                                      |
|------------------------|-----------------------------------------------|
| **Arduino (C/C++)**    | Microcontroller firmware for LED/sensor demos |
| **Arduino Uno**        | Target development board                      |
| **Python 3**           | CI helper script (`count_ino.py`)             |
| **GitHub Actions**     | Continuous integration on every push          |
| **Git**                | Version control and branching strategy        |
| **Markdown**           | Documentation                                 |

---

## 🌿 Git Workflow

This repository follows a lightweight feature-branch workflow:

| Branch             | Purpose                                              |
|---------------------|-------------------------------------------------------|
| `main`             | Stable, submission-ready code only                    |
| `dev`               | Integration branch for in-progress weekly work        |
| `sensor-module`     | Feature branch for sensor-related sketches            |
| `wireless-module`   | Feature branch for wireless/connectivity features      |

See [`notes.md`](notes.md) for a full explanation of each branch's role and the
merge strategy used between them.

---

## 📊 Repository Statistics

> Badges below activate automatically once this repository is pushed to GitHub
> under your own account — replace `<your-username>` in the URLs.

![Repo Size](https://img.shields.io/github/repo-size/%3Cyour-username%3E/iot-summer-school-2026)
![Last Commit](https://img.shields.io/github/last-commit/%3Cyour-username%3E/iot-summer-school-2026)
![Issues](https://img.shields.io/github/issues/%3Cyour-username%3E/iot-summer-school-2026)
![Commit Activity](https://img.shields.io/github/commit-activity/m/%3Cyour-username%3E/iot-summer-school-2026)

---

## 🚀 Future Work

- [ ] Add Week 2 sensor integration (temperature/humidity)
- [ ] Add Week 3 wireless communication module (ESP8266/BLE)
- [ ] Build final capstone project combining sensing + connectivity
- [ ] Expand CI workflow to lint C++ style, not just count files
- [ ] Add hardware wiring diagrams (Fritzing) for each week

---

## 🤝 Contribution Guidelines

This is an individual coursework repository, but the workflow follows standard
open-source practices:

1. Create a feature branch off `dev` (e.g. `git checkout -b sensor-module`)
2. Make focused commits using [Conventional Commits](https://www.conventionalcommits.org/)
3. Open a Pull Request into `dev` with a clear description and checklist
4. Merge into `main` only once the code is tested and documented

---

## 📄 License

This project is licensed under the **MIT License** — see [`LICENSE`](LICENSE) for details.
