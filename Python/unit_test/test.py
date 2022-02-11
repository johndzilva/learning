import unittest
import main

class TestMain(unittest.TestCase):
    def test_double_num(self):
        test_param = 5
        result = main.double_num(test_param)
        self.assertEqual(result, 10)

    def test_double_num2(self):
        test_param = "sfdgs"
        result = main.double_num(test_param)
        self.assertTrue(isinstance(result, ValueError))

    def test_double_num3(self):
        test_param = None
        result = main.double_num(test_param)
        self.assertEqual(result, 'please enter number')

if __name__ == "__main__":
    unittest.main()