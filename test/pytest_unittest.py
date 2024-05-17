import pytest
from pytest_embedded import Dut

def test_unit_test(dut: Dut) -> None:
    dut.expect("0 Failures")
    dut.expect("Returned from app_main")
