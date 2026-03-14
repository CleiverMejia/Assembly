sect .data
    text "Hello world\n"

sect .text
    load a, 4
    load b, 1
    load c, text
    load d, 12
    sys

    load a, 1
    load b, 0
    sys