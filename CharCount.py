def char_count(data):
    words = data.split(" ")
    framed_data = ""

    for word in words:
        framed_data += f"{len(word)+1}{word}"
        
    print("Framed Data: ", framed_data.strip())


data = input("Input Data: ")
char_count(data)
