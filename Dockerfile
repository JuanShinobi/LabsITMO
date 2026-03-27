FROM ubuntu:22.04

RUN apt update && apt install -y nano

WORKDIR /app

COPY script.sh /app/script.sh

RUN chmod +x /app/script.sh

CMD ["./script.sh"]
