FROM gcc:latest

WORKDIR /code

COPY . .

RUN g++ ./test_main.cpp main.cpp -o test

CMD ["./test"]