# A function to take a vector of numbers and give a CI lower bound
#
# Uses the standard one for normal data with an unknown variance
# That is, this calculates the lower bound for a one sample test
# Using a t-distribution.
#
# arguments:
# x: a vector of numbers
# level: The strength of your confidence interval, i.e. 0.95 for 95%
#
# returns:
# vector with the lower point
get_lwr_ci <- function(x, level = 0.95){
  # get mean
  m <- mean(x, na.rm = TRUE)
  # get SE
  s <- sd(x, na.rm = TRUE)
  n <- length(x)
  se <- s / sqrt(n)
  # get t cutoff point
  a <- (1 - level) / 2
  t <- qt(a, df = n-1, lower.tail = FALSE)
  # lower point
  lwr <- m - t * se
  # return
  return(lwr)
}