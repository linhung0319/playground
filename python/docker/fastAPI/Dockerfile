FROM python:3.9

WORKDIR /fastapi-app

COPY requirements.txt .

RUN pip install -r requirements.txt

ADD main.py .

CMD ["python", "main.py"]