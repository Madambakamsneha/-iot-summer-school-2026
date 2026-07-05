# 📋 GitHub Issues & Pull Request — Week 1

GitHub Issues and Pull Requests are created through GitHub itself (the web
UI or `gh` CLI), not as files inside the repository. This document contains
the exact, ready-to-use content for each one — copy it directly into GitHub,
or run the `gh` CLI commands in [`../setup-commands.ps1`](../setup-commands.ps1)
to create them automatically.

---

## 🐞 Q6 — GitHub Issues

**Milestone for all three issues:** `Week 1 Completion`

---

### Issue #1

**Title:** `Create basic LED blink sketch`

**Labels:** `enhancement`, `week-1`

**Description:**
```
## Description
Implement the baseline LED blink sketch for the Week 1 assignment.
The onboard LED should turn ON and OFF at a fixed interval to verify
the board, IDE, and upload toolchain are all working correctly.

## Acceptance Criteria
- [ ] `led_blink.ino` created under `week1/led_blink/`
- [ ] LED blinks at a visibly fixed interval
- [ ] Sketch compiles and uploads without errors

## Related Files
- week1/led_blink/led_blink.ino
```

---

### Issue #2

**Title:** `Add Serial Monitor blink counter`

**Labels:** `enhancement`, `week-1`

**Description:**
```
## Description
Extend the basic blink sketch to report a running blink count over
the Serial Monitor, so the number of completed ON/OFF cycles is
visible in real time.

## Acceptance Criteria
- [ ] Serial communication initialized at 9600 baud
- [ ] Blink count increments once per full ON/OFF cycle
- [ ] Count is printed to Serial Monitor after every blink

## Related Files
- week1/led_blink/versions/v1.1_serial_blink_counter.ino
```

---

### Issue #3

**Title:** `Add potentiometer-controlled blink speed`

**Labels:** `enhancement`, `hardware`, `week-1`

**Description:**
```
## Description
Add support for a potentiometer connected to A0 that controls the
LED blink delay in real time, demonstrating analog input handling.

## Acceptance Criteria
- [ ] Potentiometer wired to A0 per the circuit diagram in README
- [ ] analogRead() value mapped to a sensible delay range (50-1000ms)
- [ ] Turning the potentiometer visibly changes blink speed live

## Related Files
- week1/led_blink/versions/v1.2_potentiometer_control.ino
```

---

### Commit message closing an issue

When committing the fix for Issue #1, reference it directly so GitHub
auto-closes the issue on merge:

```
feat: add LED blink starter code

Fixes #1
```

---

## 🔀 Q7 — Pull Request: `blink_modified.ino`

**Branch:** `feature/blink-modified` → `dev`

**Title:**
```
feat: add modified blink pattern (3 fast blinks + 2s pause)
```

**Description:**
```
## Summary
Adds `week1/blink_modified.ino`, implementing a modified LED blink
pattern as required by Q7 of the Week 1 assignment.

## Behavior
- LED blinks 3 times quickly (150ms ON / 150ms OFF)
- Followed by a 2-second pause
- Pattern repeats indefinitely

## Testing
- [x] Compiled successfully in Arduino IDE
- [x] Uploaded to Arduino Uno and visually verified blink pattern
- [x] Timing confirmed with a stopwatch against expected pattern

## Checklist
- [x] Code follows the repository's style conventions
- [x] Sketch compiles without warnings
- [x] README/documentation updated where relevant
- [x] Commit messages follow Conventional Commits
- [ ] Reviewed and approved by a peer/instructor
```

---

## 🖥️ Creating These via GitHub CLI (`gh`)

If you have the [GitHub CLI](https://cli.github.com/) installed and
authenticated (`gh auth login`), the three issues and milestone can be
created directly from PowerShell — see the full command sequence in
[`../setup-commands.ps1`](../setup-commands.ps1).
