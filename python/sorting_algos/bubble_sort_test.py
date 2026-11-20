from bubble_sort import bubble_sort
import pytest

run_cases = [
    pytest.param([5,7,3,6,8], [3,5,6,7,8,]),
    pytest.param([2,1], [1,2]),
]

@pytest.mark.parametrize(("input1", "expected_output"), run_cases)
def test_bubble_sort(input1, expected_output):
    print("\n-----------------------------------")
    print(f"Input:\n * {input1}")
    print(f"Expected: {expected_output}")
    result = bubble_sort(input1)
    print(f"Actual: {result}")
    assert result == expected_output
