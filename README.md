# Playground for the Tiva C Series Launchpad

Board: [Tiva C Series Launchpad (EK-TM4C123GXL)](http://www.ti.com/ww/en/launchpad/launchpads-connected-ek-tm4c123gxl.html).

The project source is in **src**.

Unit tests are in **test**.

The TivaWare Peripheral Driver Library is in **lib/TivaWare/driverlib** and is built automatically if necessary.

## Building and loading

Execute all unit tests with `ceedling test:all`.

Run a single test with `ceedling test:<module>`, e.g. `ceedling test:led`.

Build the application for the target with: `ceedling release`.

Load the app on the board with: `ceedling load`. The load command also builds the application if necessary.
