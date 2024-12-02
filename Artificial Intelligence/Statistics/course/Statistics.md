**Adjusted R-squared** is a modified version of the R-squared statistic that adjusts for the number of predictors in a regression model. While R-squared provides a measure of how well the model explains the variance in the dependent variable, it can be misleading when comparing models with different numbers of predictors. The Adjusted R-squared corrects for this issue by accounting for the degrees of freedom.

### Formula for Adjusted R-squared:

$\[
\text{Adjusted R}^2 = 1 - \left(\frac{(1 - R^2)(n - 1)}{n - p - 1}\right)
\]$

Where:
- $\( R^2 \)$ = Coefficient of determination (regular R-squared)
- \( n \) = Number of data points (sample size)
- \( p \) = Number of predictors (independent variables) in the model

### Key Features:
1. **Penalty for Extra Predictors**: The adjusted R-squared penalizes the addition of unnecessary predictors. If a new predictor does not improve the model significantly, the adjusted R-squared will decrease.
   
2. **Interpretation**: 
   - If you add predictors to a model, and the adjusted R-squared increases, it means the new predictors contribute to explaining the variance in the dependent variable.
   - If the adjusted R-squared decreases, the new predictors don't improve the model sufficiently, or they might be redundant.

3. **Range**: Like regular R-squared, adjusted R-squared ranges from 0 to 1, but it can also be negative if the model is a poor fit to the data.

### Why Adjusted R-squared is Useful:
- **Model Comparison**: It’s particularly useful when comparing models with a different number of predictors. Unlike R-squared, which can artificially increase with more predictors, adjusted R-squared will only increase if the new predictor improves the model.
- **Avoid Overfitting**: Adjusted R-squared helps guard against overfitting, which can occur when too many predictors are included in the model.

### Example:
Imagine you have two models:
- Model 1 has 2 predictors and an R-squared of 0.75.
- Model 2 has 5 predictors and an R-squared of 0.78.

Even though Model 2 has a higher R-squared, the adjusted R-squared might be lower, indicating that the extra predictors don't significantly improve the model’s ability to explain the variance in the dependent variable.

