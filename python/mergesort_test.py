from mergesort import merge_sort
import pytest

run_cases = [
    pytest.param([10,2,-3,0,1,1], [-3,0,1,1,2,10]),
    pytest.param([], []),
    pytest.param([1],[1]),
    pytest.param([4, -7, 1, 0, 5], [-7,0,1,4,5])
]

@pytest.mark.parametrize(("input1", "expected_output"), run_cases)
def test_merge_sort(input1, expected_output):
    print("\n-----------------------------------")
    print(f"Input:\n * {input1}")
    print(f"Expected: {expected_output}")
    result = merge_sort(input1)
    print(f"Actual: {result}")
    assert result == expected_output

