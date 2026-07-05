# 🌿 Git Branching Strategy — Notes

This document explains the branching model used throughout the
`iot-summer-school-2026` repository and why each branch exists.

## Overview Diagram

```
main
 │
 └── dev
      │
      ├── sensor-module
      └── wireless-module
```

`main` only ever receives finished, working code via merges from `dev`.
`dev` is where weekly work is integrated before it's considered stable.
Feature branches (`sensor-module`, `wireless-module`) are short-lived
branches used to build a specific capability in isolation.

---

## `main`

**Purpose:** The stable, submission-ready branch.

- Always contains code that compiles and runs correctly.
- Never receives direct commits — only merges from `dev` via reviewed
  Pull Requests.
- Represents the state of the project at each graded milestone.

## `dev`

**Purpose:** The integration branch for active coursework.

- Weekly folders (`week1/`, `week2/`, `week3/`) are developed here first.
- Feature branches merge back into `dev` once their functionality is
  complete and tested.
- `dev` is merged into `main` only once a milestone (e.g. "Week 1
  Completion") is fully done.

## `sensor-module`

**Purpose:** Feature branch for sensor-related development.

- Used to build and test sensor input code (e.g. potentiometer readings,
  temperature/humidity sensors planned for Week 2) without affecting the
  stable `dev` branch.
- Merged into `dev` once the sensor logic is verified on hardware.

## `wireless-module`

**Purpose:** Feature branch for wireless/connectivity development.

- Reserved for wireless communication work (e.g. ESP8266 Wi-Fi, BLE)
  planned for Week 3 and the final project.
- Kept isolated from `dev` until the wireless stack is stable, since
  connectivity code tends to be the most experimental and failure-prone
  part of an IoT build.

---

## Why This Model?

| Benefit                          | Explanation                                                       |
|-----------------------------------|---------------------------------------------------------------------|
| **Safety**                        | `main` is never broken by work-in-progress code                    |
| **Parallel development**          | Sensor and wireless work can proceed independently                 |
| **Clear history**                 | Pull Requests document *why* each feature was added                |
| **Realistic practice**            | Mirrors how small engineering teams actually use Git day-to-day    |

## Typical Merge Flow

```powershell
# Finish work on a feature branch
git checkout sensor-module
git add .
git commit -m "feat: add potentiometer-based delay control"

# Merge feature into dev
git checkout dev
git merge sensor-module

# Once dev is verified stable, promote to main
git checkout main
git merge dev
git push origin main
```

Last updated for Module 1 submission.