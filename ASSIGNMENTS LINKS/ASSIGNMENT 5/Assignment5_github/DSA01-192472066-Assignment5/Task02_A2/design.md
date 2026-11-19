# A2 – Binding, Vtables and Virtual Destructors

## Early and late binding
A non-virtual function call is resolved using the static type known at compile time. A virtual call through `Bill*` is dispatched at runtime to the final overrider for the object's dynamic type.

## Conceptual vtable sketch
A vtable is an implementation mechanism used by common C++ ABIs; the language standard does not require a particular physical layout.

```text
Bill vtable (conceptual)
  destructor -> Bill destructor
  total      -> pure virtual slot

OutPatientBill vtable
  destructor -> OutPatientBill destructor
  total      -> OutPatientBill::total

InPatientBill vtable
  destructor -> InPatientBill destructor
  total      -> InPatientBill::total
```

For `b->total()`, the object's dynamic type determines the final overrider. The call reaches the derived implementation.

## Virtual destructor
Deleting a derived object through a pointer to a polymorphic base requires a virtual base destructor for defined behaviour and correct derived cleanup. Otherwise behaviour is undefined; do not assume a consistent sanitizer message or destructor trace.

## Prediction for supplied program
The normal expected output is:

```text
500 ~OPBill ~Bill
```

`show()` is non-virtual but calls virtual `total()`, so the inner call dispatches to `OPBill::total()`. If the base destructor is made non-virtual, deleting through `Bill*` has undefined behaviour.
