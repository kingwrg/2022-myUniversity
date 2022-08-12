library(tidyverse)
library(readxl)
dirty_data <- read_excel("dirty_data.xlsx")
dirty_data[1,]
dirty_data[,1]
dirty_data$name
dirty_data[10,4]
dirty_data[,3]

# Find all prices that are "NA" and set to NA. 
table(dirty_data$gender)
dirty_data$gender[dirty_data$gender == "-"] <- NA
table(dirty_data$gender)
table(dirty_data$gender, useNA = 'always')

dirty_data$gender  <- fct_recode(dirty_data$gender, 
                                 female = "Female", 
                                 female = "F", 
                                 male = "Male")
table(dirty_data$gender)
dirty_data
class(dirty_data$weight)

table(dirty_data$weight)
dirty_data$weight[dirty_data$weight == "-"] <- NA
table(dirty_data$weight)
table(dirty_data$weight, useNA = 'always')
dirty_data$weight  <- as.numeric(dirty_data$weight)

summary(dirty_data$weight)
mean(dirty_data$weight, na.rm = TRUE)
sd(dirty_data$weight, na.rm = TRUE)
median(dirty_data$weight, na.rm = TRUE)
ggplot(dirty_data,aes(weight)) + geom_histogram()

write_rds(dirty_data, "dirty_data.rds")