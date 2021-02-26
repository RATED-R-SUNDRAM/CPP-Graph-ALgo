import numpy as np


class PolynomialRegression():
    def init(self, degree, learning_rate=0.01, iterations=100):
        self.degree = degree
        self.learning_rate = learning_rate
        self.iterations = iterations

    def transform(self, X):

        X_transform = np.ones((self.m, 1))
        j = 0
        for j in range(self.degree + 1):
            if j != 0:
                x_pow = np.power(X, j)
                X_transform = np.append(X_transform, x_pow.reshape(-1, 1), axis=1)   # noqa

        return X_transform

    def normalize(self, X):
        X[:, 1:] = (X[:, 1:] - np.mean(X[:, 1:], axis=0)) / np.std(X[:, 1:], axis=0)  # noqa
        return X

    def fit(self, X, Y):
        self.X = X

        self.Y = Y

        self.m, self.n = self.X.shape

        # weight initialization

        self.W = np.zeros(self.degree + 1)

        X_transform = self.transform(self.X)

        # normalize X_transform

        x_normalize = self.normalize(X_transform)

        # gradient descent learning

        for i in range(self.iterations):
            h = self.predict(self.X)

            error = h - self.Y

            # update weights

            self.W = self.W - self.learning_rate * (1 / self.m) * np.dot(x_normalize.T, error)  # noqa
        return self

    def predict(self, X):
   # tranform X for polynomial h( x ) = w0 * x^0+ w1 * x^1 + w2 * x^2 + ........+ wn * x^   # noqa

        X_transform = self.transform(X)

        return np.dot(X_transform, self.W)

    def accuracy(self, y_pred, y):
        y_mean = sum(y) / len(y)
        y_pred_mean = sum(y_pred) / len(y)
        sumsquaredregression = 0
        totalsumofsquares = 0
        for i in range(len(y)):
            sumsquaredregression += (y_pred[i] - y_pred_mean) ** 2
            totalsumofsquares += (y[i] - y_mean) ** 2
        accuracy = ((sumsquaredregression) / totalsumofsquares)
        return accuracy * 100

    def rmse(self, y_pred, y):
        ans = 0
        for i in range(len(y_pred)):
            ans += (y_pred[i] - y[i]) ** 2
        return (ans / len(y)) ** 0.5
# The above code generates a polunomial regression class in models.py file
