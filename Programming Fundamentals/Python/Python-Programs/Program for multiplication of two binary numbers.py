def multiply_binary(num1, num2):
    # convert binary numbers to decimal
    num1_dec = int(num1, 2)
    num2_dec = int(num2, 2)

    # perform multiplication
    result_dec = num1_dec * num2_dec

    # convert result back to binary
    result_bin = bin(result_dec)[2:]

    return result_bin
