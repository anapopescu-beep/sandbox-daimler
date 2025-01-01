# Components

This directory contains the main software components, organized by function and supplier.

## Structure
- **Application/**: Application-level source code.
- **BM/**, **FBL/**, **FBL_UPDATER/**, **FBLBM_UPDATER/**, **HSM/**, **HSM_UPDATER/**: Bootloader, HSM, and updater modules.
- Each component has subfolders for different suppliers (e.g., `Autoliv/`, `Supplier/`).

## Interactive Tips
- Explore C source/header files for implementation details.
- Each supplier folder may have its own README or documentation.
- Use VS Code's "Go to Definition" and "Find All References" for code navigation.

## Technical Details
- Written mainly in C/C++ for embedded systems.
- Look for `*.c` and `*.h` files for source and interface definitions.
