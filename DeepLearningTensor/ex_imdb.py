import tensorflow as tf
from tensorflow.keras import datasets, layers, models, preprocessing
import tensorflow_datasets as tfds
import numpy as np

max_len = 200
n_words = 10000
dim_embedding = 256
EPOCHS = 20
BATCH_SIZE = 500

def load_data():
    (X_train, Y_train), (X_test, Y_test) = datasets.imdb.load_data(num_words=n_words)
    X_train = preprocessing.sequence.pad_sequences(X_train, maxlen=max_len)
    X_test = preprocessing.sequence.pad_sequences(X_test, maxlen=max_len)
    return (X_train, Y_train), (X_test, Y_test)

def build_model():
    model = models.Sequential()
    model.add(layers.Embedding(n_words, dim_embedding, input_length=max_len, input_shape=(max_len,)))
    model.add(layers.Dropout(0.3))
    model.add(layers.GlobalMaxPooling1D())
    model.add(layers.Dense(128, activation='relu'))
    model.add(layers.Dropout(0.5))
    model.add(layers.Dense(1, activation='sigmoid'))
    return model

# train the model
#
(X_train, Y_train), (X_test, Y_test) = load_data()

model = build_model()
model.summary()
model.compile(
    optimizer='adam',
    loss='binary_crossentropy',
    metrics=['accuracy']
)

history = model.fit(
    X_train, Y_train,
    epochs=EPOCHS,
    batch_size=BATCH_SIZE,
    validation_data=(X_test, Y_test),
    verbose=1
)

score = model.evaluate(X_test, Y_test, batch_size=BATCH_SIZE)
print(f"\nTest score:{score[0]}   accuracy:{score[1]}")
