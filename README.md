# sandbox-daimler

Welcome to the **sandbox-daimler** repository! This workspace contains a modular automotive software project for automotive ECUs (Electronic Control Units), focusing on embedded systems, safety, diagnostics, and compliance with industry standards. This project implements an AUTOSAR-compliant ECU. Below you'll find an interactive guide to the structure, technical details, and how to get started.

---

## 🔑 Technical Keywords



**MCU / Microcontroller:**
- **Platform in use:** Infineon AURIX2G (TriCore tc33x)
- **Core:** TriCore (tc33x variant)
- **Vendor:** Infineon Technologies
- **Toolchain:** TASKING VX-toolset for TriCore
- Used for real-time control, safety, and diagnostics in automotive ECUs

**ECU Functions and Main Functionalities:**
	- This project concerns a single automotive ECU for occupant safety, diagnostics, and secure boot.
	- Main features include:
		- Crash detection, occupant protection, and airbag deployment
		- Boot process management, secure startup, and firmware integrity checks (Boot Manager)
		- Firmware flashing, update, and rollback (Bootloader, Updater)
		- Cryptographic operations, secure key storage, and authentication (HSM)
		- Vehicle diagnostics (UDS/KWP), error logging, and reporting
		- Communication over CAN, LIN, FlexRay
		- Functional safety (ISO 26262 compliance, ASIL levels)
		- Traceability, static analysis, and quality assurance

**Product Details:**
- Automotive ECUs for occupant safety (airbag, seatbelt), secure boot, and diagnostics
- Boot Manager (BM) is responsible for secure boot, firmware validation, and update coordination
- Suppliers: Autoliv and others
- Modules: Bootloader (FBL), HSM (Hardware Security Module), Boot Manager (BM), Updater modules

**Norms & Protocols:**
- AUTOSAR (Automotive Open System Architecture)
- CAN, LIN, FlexRay (vehicle communication protocols)
- ISO 26262 (Functional Safety, ASIL levels)
- UDS (ISO 14229), KWP (ISO 14230) for diagnostics
- Security: HSM, cryptographic modules

**Compliance & Quality:**
- Static analysis (QAC), code coverage, traceability
- Integration/unit testing, safety-relevant requirements
- Reports and metrics for quality assurance

**Release & Traceability:**
- Binaries: ELF, HEX, MAP files
- Test and coverage reports
- Traceability to requirements and architecture

---

---


## 📁 Main Directory Structure

- **Architectures/**: System and application architecture documentation (DOCX, diagrams, requirements)
- **Components/**: Source code for application, bootloader (FBL), HSM, BM, updater modules, organized by supplier (Autoliv, etc.)
- **Methods/**: Guides and how-tos for building, flashing, and development processes (DOCX)
- **Metrics/**: Reports and scripts for static analysis (QAC), integration, and unit testing (Python, BAT, DOCX, XLSX)
- **Releases/**: Compiled binaries (ELF, HEX), maps, and production deliverables for each release
- **Scripts/**: Automation scripts for build, test, reporting, and configuration management (Python, BAT)
- **Tools/**: Tooling for build environments, CANoe, Eclipse, Python, AUTOSAR, Doxygen, etc.

---


## 🚀 Getting Started

1. **Explore the Architecture**: See `Architectures/Application/Description/` for design interface docs (DOCX, AUTOSAR ARXML)
2. **Build & Flash**: Follow the guides in `Methods/HowTo/` (DOCX) for step-by-step instructions
3. **Run Static Analysis**: Use scripts in `Metrics/Static_Analysis/` (e.g., `run_qac.bat`, `PP4G_QAC_Analysis.py`) for compliance and code quality
4. **Check Releases**: Find binaries and maps in `Releases/R09.0_P91/` (ELF, HEX, MAP)
5. **Automate Tasks**: Leverage Python and batch scripts in `Scripts/` for CI/CD, reporting, and more

---


## 🛠️ Key Technologies & Protocols

- **C/C++**: Main embedded codebase (`Components/`)
- **Python**: Automation and analysis scripts (`Scripts/`, `Metrics/`)
- **Batch Scripts**: Windows automation for builds and reports
**AUTOSAR ARXML**: Architecture and configuration (multiple locations in Components/)
- **CAN, LIN, FlexRay**: Vehicle communication protocols
- **UDS, KWP**: Diagnostic protocols
- **DOCX/XLSX**: Documentation and metrics

---


## 📚 Documentation & Interactive Exploration

- **Design Docs**: See the [Architectures](./Architectures/README.md) directory for interface specs, requirements, and diagrams.
**AUTOSAR Configs**: See Components/ for ARXML configuration files
- **How-To Guides**: `Methods/HowTo/` (build, flash, compliance)
- **Test Reports**: `Metrics/Integration_Test/`, `Metrics/Unit_Test/` (DOCX)
- **Static Analysis**: `Metrics/Static_Analysis/` (QAC, compliance, safety)

---


## 🧩 Contributing

- Add new components in the appropriate `Components/` subfolder (C/C++, AUTOSAR)
- Update or add scripts in `Scripts/` for automation (Python, BAT)
- Place new documentation in the relevant `Architectures/` or `Methods/` directory (DOCX, ARXML)

---






## 📢 Interactive Tips

- **Search for keywords like MCU, AUTOSAR, CAN, UDS, ISO, ASIL, HSM, FBL, BM, supplier, product, diagnostic, safety, compliance, traceability, test, coverage, report in the codebase for technical details.**
- **Click on any folder above in VS Code to explore its contents.**
- **Open DOCX/XLSX files directly in VS Code with the right extension.**
- **Run Python scripts from the terminal for automation.**

---


For more details, see the README files in each significant directory:

- [Architectures](./Architectures/README.md)
- [Components](./Components/README.md)
- [Methods](./Methods/README.md)
- [Metrics](./Metrics/README.md)
- [Releases](./Releases/README.md)
- [Scripts](./Scripts/README.md)
- [Tools](./Tools/README.md)
