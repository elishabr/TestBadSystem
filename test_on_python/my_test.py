import numpy as np
from scipy import stats

random_numbers = stats.weibull_max.pdf(np.array([0.1, 0.2, 0.3]), 2.0, 2.0)
print(random_numbers[:3])