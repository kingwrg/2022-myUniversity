get_upr_ci <- function(x, level = 0.95){
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
  upr <- m + t * se
  # return
  return(upr)
}