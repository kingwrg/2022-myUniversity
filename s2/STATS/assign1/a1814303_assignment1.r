# Marcus Hoang - a1814303
library(tidyverse)
library(readr)
dirty_data <- read.csv('survey2003_dirty.csv')

# question 1
# b
# check values that may be incorrectly entered and then set them to NA
table(dirty_data$particiant_id, useNA = 'always')
table(dirty_data$favourite_genre, useNA = 'always')
table(dirty_data$sleep_hr, useNA = 'always')
table(dirty_data$TV_hr, useNA = 'always')
table(dirty_data$height, useNA = 'always')
table(dirty_data$weight, useNA = 'always')
table(dirty_data$gender, useNA = 'always')

dirty_data$weight[dirty_data$weight == ""] <- NA
dirty_data$weight[dirty_data$weight == "."] <- NA
dirty_data$weight[dirty_data$weight == "not measured"] <- NA
dirty_data$height[dirty_data$height == "-"] <- NA

# a)
# Ensure each variable is the right class
class(dirty_data$particiant_id)
class(dirty_data$favourite_genre)
class(dirty_data$sleep_hr)
class(dirty_data$TV_hr)
class(dirty_data$height)
class(dirty_data$weight)
class(dirty_data$gender)

# Class of height and weight variables should be numeric not character
dirty_data$height <- as.numeric(dirty_data$height)
dirty_data$weight <- as.numeric(dirty_data$weight)


# c)
# Some values that are incorrectly entered
# sleep_hr
# check all participant that has sleep_hr more than 24 hours or negative numbers
dirty_data$particiant_id[dirty_data$sleep_hr > 24]
dirty_data$particiant_id[dirty_data$sleep_hr < 0]
# Participant 45 has extreme high sleep hour: 705.00
dirty_data[45,]
# Participant 117 has extreme high sleep hour: 707.00
dirty_data[117,]

# TV_hr
# check all participant that has TV_hr more than 24 hours or negative numbers
dirty_data$particiant_id[dirty_data$TV_hr > 24]
dirty_data$particiant_id[dirty_data$TV_hr < 0]
# Participant 82 has negative TV_hour value: -206.0
dirty_data[82,]
# Participant 85 has negative TV_hour value: -0.5
dirty_data[85,]
# Participant 94 has negative TV_hour value: -0.6
dirty_data[94,]
# Participant 99 has negative TV_hour value: -0.5
dirty_data[99,]
# Participant 103 has negative TV_hour value: -0.1
dirty_data[103,]
# Participant 108 has negative TV_hour value: -0.1
dirty_data[108,]
# Participant 124 has negative TV_hour value: -1.0
dirty_data[124,]
# Participant 128 has negative TV_hour value: -0.1
dirty_data[128,]
# Participant 137 has negative TV_hour value: -0.1
dirty_data[137,]
# Participant 139 has negative TV_hour value: -1.1
dirty_data[139,]
# Participant 146 has negative TV_hour value: -0.7
dirty_data[146,]

# height
dirty_data$particiant_id[dirty_data$height > 300]
dirty_data$particiant_id[dirty_data$height < 50]
# Participant 19 has extremely high value: 1865.00
dirty_data[19,]
# Participant 9 has extremely low height value: 1.78
dirty_data[9,]
# Participant 116 has extremely low height value: 16.4
dirty_data[116,]

# weight
dirty_data$particiant_id[dirty_data$weight > 200]
dirty_data$particiant_id[dirty_data$weight < 30]
# 4.1 kg is not extreme for a baby but a 158cm person can not weight 4.1 kg (4.1)
# therefore this is a incorrectly entered value
dirty_data[151,]

# Remove incorrectly entered value (set them to NA)
dirty_data$sleep_hr[dirty_data$sleep_hr > 24] <- NA
dirty_data$TV_hr[dirty_data$TV_hr < 0] <- NA
dirty_data$height[dirty_data$height > 300] <- NA
dirty_data$height[dirty_data$height < 50] <- NA
dirty_data$weight[dirty_data$weight < 30] <- NA

# d)
# Recode factors of favourite_genre to three main kinds: action, comedy, thriller
dirty_data$favourite_genre <- fct_recode(dirty_data$favourite_genre,
                                         action = "actin",
                                         comedy = "comdy",
                                         comedy = "Comedy",
                                         thriller = "Thriler",
                                         thriller = "thrller")

# Recode factors of favourite_genre to two main kinds: Female and Male
dirty_data$gender <- fct_recode(dirty_data$gender,
                                Female = "F",
                                Male = "M")

# question 2:
# Plot histograms and bar charts for variables
ggplot(dirty_data, aes(favourite_genre)) + geom_bar(colour = 1,
                                                    fill = 'red')
ggplot(dirty_data,aes(sleep_hr))+geom_histogram(colour = 1,
                                                fill = 'red',
                                                binwidth = 1)
ggplot(dirty_data,aes(TV_hr))+geom_histogram(colour = 1,
                                             fill = 'red',
                                             binwidth = 1)
ggplot(dirty_data,aes(height))+geom_histogram(colour = 1,
                                              fill = 'red',
                                              binwidth = 1)
ggplot(dirty_data,aes(weight))+geom_histogram(colour = 1,
                                              fill = 'red',
                                              binwidth = 1)
ggplot(dirty_data, aes(gender)) + geom_bar(colour = 1,
                                           fill = 'red')

# question 3:
# From above histograms and bar charts, I can conclude:
# quantitative variables:
# sleep_hr: relatively symmetric, unimodel
# TV_hr: right skewed, unimodel
# height: left skewed, unimodel
# weight: relatively symmetric, unimodel

# categorical variables (most common level):
# favourite_genre: comedy
# gender: Male

# question 4:
# function to get five-number summaries for quantitative variables
five_number_summary <- function(x) {
  min <- min(x, na.rm = TRUE)
  sorted <- sort(x)
  lower <- sorted[1:round(length(sorted)/2)]
  lower <- median(lower)
  median <- median(x, na.rm = TRUE)
  upper <- sorted[round((length(sorted)/2)+1):length(sorted)]
  upper <- median(upper)
  max <- max(x, na.rm = TRUE)
  five <- cbind(min, lower, median, upper, max)
  colnames(five) <- c("Min", "Lower-hinge",
                            "Median", "Upper-hinge", "Max")
  return(five)
}

# quantitative variables (five numbers summary):
# sleep_hr:
five_number_summary(dirty_data$sleep_hr)
# TV_hr:
five_number_summary(dirty_data$TV_hr)
# height:
five_number_summary(dirty_data$height)
# weight:
five_number_summary(dirty_data$weight)

# categorical variables (frequency table):
# favourite_genre:
table(dirty_data$favourite_genre)
# gender:
table(dirty_data$gender)

# Identify missing values
# sleep_hr column has 2 NA values
# The proportion of missing sleep_hr values is 1.31%
table(dirty_data$sleep_hr, useNA = 'always')
sleep_hr_missing_proportion <- (2/153)*100
sleep_hr_missing_proportion

# Participant 45 and 117 have missing sleep_hr values
dirty_data$particiant_id[is.na(dirty_data$sleep_hr)]
dirty_data[45,]
dirty_data[117,]

# TV_hr column has 11 NA values
# The proportion of missing TV_hr values is 7.20%
table(dirty_data$TV_hr, useNA = 'always')
TV_hr_missing_proportion <- (11/153)*100
TV_hr_missing_proportion
# Participant 82, 85, 94, 99, 103, 108, 124, 128, 137, 139, and 146 have missing TV_hr values
dirty_data$particiant_id[is.na(dirty_data$TV_hr)]
dirty_data[82,]
dirty_data[85,]
dirty_data[94,]
dirty_data[99,]
dirty_data[103,]
dirty_data[108,]
dirty_data[124,]
dirty_data[128,]
dirty_data[137,]
dirty_data[139,]
dirty_data[146,]

# height column has 11 NA values
# The proportion of missing height values is 3.27%
table(dirty_data$height, useNA = 'always')
height_missing_proportion <- (5/153)*100
height_missing_proportion
# Participant 9, 15, 19, 116, and 145 have missing height values
dirty_data$particiant_id[is.na(dirty_data$height)]
dirty_data[9,]
dirty_data[15,]
dirty_data[19,]
dirty_data[116,]
dirty_data[145,]

# weight column has 4 NA's 
# The proportion of missing weight values is 2.61%
table(dirty_data$weight, useNA = 'always')
weight_missing_proportion <- (4/153)*100
weight_missing_proportion
# Participant 15, 128, 145, and 151 have missing weight values
dirty_data$particiant_id[is.na(dirty_data$weight)]
dirty_data[15,]
dirty_data[128,]
dirty_data[145,]
dirty_data[151,]

# Question 5
# Export the cleaned data into a CSV file
directory <- getwd()
write_csv(dirty_data, paste(directory,'/clean.csv', sep=""))
