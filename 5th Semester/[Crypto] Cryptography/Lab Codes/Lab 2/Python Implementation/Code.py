from random import shuffle  # shuffle(list) randomly shuffles the content of the list

_ENCRYPT = True
_DECRYPT = False

def main():
    message = "Hello world. This is a test 123."

    # Generating a random key
    key = [chr(ascii_value) for ascii_value in range(ord('A'), ord('Z') + 1)] # Creates a list of all alphabets [A-Z]
    shuffle(key)  # Shuffles the list randomly

    ciphertext = MonoalphabeticCipher(message, key, _ENCRYPT)
    plaintext = MonoalphabeticCipher(ciphertext, key, _DECRYPT)

    print("Message: " + message)
    print("Key: " + ''.join(key))
    print("Ciphertext: " + ciphertext)
    print("Plaintext: " + plaintext)

    exit()

def MonoalphabeticCipher(message, key, encrypt):
    temp_key = []
    for char in key:
        if char not in temp_key:
            temp_key.append(char)
    key = temp_key
    if len(key) != 26:
        return None
  
    # Preparing input data for processing
    for i in range(0, len(key)):
        key[i] = key[i].lower()
    message = message.lower()
  
    # Processing the text
    result = ''
    for char in message: # Looping through each character
        if char.isalpha(): # Checking if the character is an alphabet [a-z]
        # Deciding whether to encode or decode
            if encrypt:
                # Find the character in key corresponding to the [0-25] value for the character in text
                result += key[ord(char) - ord('a')] # Append the encoded character to the result
            else:
                # Find the alphabet corresponding to the ascii value of the character in text matching the [0-25] value of the character in key
                result += chr(key.index(char) + ord('a')) # Append the decoded character to the result
        else:
            result += char  # Append the non-alphabetic characterts to the result
  
    # Formatting the result
    if encrypt: # Returning upper cased text if encoding
        return result.upper()
    else: # Returning lower cased text if decoding
        return result.lower()

main()