import pytest
from insertion_sort import insertion_sort


test_cases = [
    pytest.param([5,7,3,6,8], [3,5,6,7,8,]),
    pytest.param([2,1], [1,2]),
    pytest.param([10,-2,32,32,0,1], [-2,0,1,10,32,32]),
    pytest.param([], []),
    pytest.param([1], [1]),
    pytest.param([6,6,6,6,6,6,6], [6,6,6,6,6,6,6]),
]

@pytest.mark.parametrize(("input1", "expected_output"), test_cases)
def test_insertion_sort(input1, expected_output):
    print("\n-----------------------------------")
    print(f"Input:\n * {input1}")
    print(f"Expected: {expected_output}")
    result = insertion_sort(input1)
    print(f"Actual: {result}")
    assert result == expected_output

