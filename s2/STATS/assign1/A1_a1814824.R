# Library
library(tidyverse)
library(readxl)

# Load data
dirty <- read.csv("survey2003_dirty.csv")

# 1.
# b. Make sure NA values are correctly entered
# Check missing data in the data set
table(dirty$particiant_id, useNA = 'always')
table(dirty$favourite_genre, useNA = 'always')
table(dirty$sleep_hr, useNA = 'always')
table(dirty$TV_hr, useNA = 'always')
table(dirty$height, useNA = 'always')
table(dirty$weight, useNA = 'always')
table(dirty$gender, useNA = 'always')

dirty$height[dirty$height == "-"] <- NA
dirty$weight[dirty$weight == ""] <- NA
dirty$weight[dirty$weight == "."] <- NA
dirty$weight[dirty$weight == "not measured"] <- NA

# a. Ensure each variable is the right class
# Check class of each variables
class(dirty$particiant_id)
class(dirty$favourite_genre)
class(dirty$sleep_hr)
class(dirty$TV_hr)
class(dirty$height)
class(dirty$weight)
class(dirty$gender)

# height and weight are in the wrong class. They should be numeric
# Convert height and weight class to numeric
dirty$height  <- as.numeric(dirty$height)
dirty$weight  <- as.numeric(dirty$weight)

# c. Identify any values that may be incorrectly entered
# Then make them NA so there are less influence
# height
dirty$particiant_id[dirty$height > 300]
dirty$particiant_id[dirty$height < 50]
# -Participant 19, height value is abnormally high (1865.00) 
dirty[19,]
# -Participant 9, height value is abnormally low (1.78) 
dirty[9,]
# -Participant 116, height value is abnormally low (16.4) 
dirty[116,]

# weight
dirty$particiant_id[dirty$weight > 200]
dirty$particiant_id[dirty$weight < 20]
# -Participant 151, weight value is abnormally low (4.1)
dirty[151,]

#sleep_hr
dirty$particiant_id[dirty$sleep_hr > 24]
dirty$particiant_id[dirty$sleep_hr < 0]
# -Participant 45, sleep hour value is abnormally high (705.00)
dirty[45,]
# -Participant 117, sleep hour value is abnormally high (707.00)
dirty[117,]

#TV_hr
dirty$particiant_id[dirty$TV_hr > 24]
dirty$particiant_id[dirty$TV_hr < 0]
# -Participant 82, negative TV hour value (-206.0)
dirty[82,]
# -Participant 85, negative TV hour value (-0.5)
dirty[85,]
# -Participant 94, negative TV hour value (-0.6)
dirty[94,]
# -Participant 99, negative TV hour value (-0.5)
dirty[99,]
# -Participant 103, negative TV hour value (-0.1)
dirty[103,]
# -Participant 108, negative TV hour value (-0.1)
dirty[108,]
# -Participant 124, negative TV hour value (-1)
dirty[124,]
# -Participant 128, negative TV hour value (-0.1)
dirty[128,]
# -Participant 137, negative TV hour value (-0.1)
dirty[137,]
# -Participant 139, negative TV hour value (-1.1)
dirty[139,]
# -Participant 146, negative TV hour value (-0.7)
dirty[146,]

# Remove incorrectly values
dirty$height[dirty$height > 300] <- NA
dirty$height[dirty$height < 50] <- NA
dirty$weight[dirty$weight < 20] <- NA
dirty$sleep_hr[dirty$sleep_hr > 24] <- NA
dirty$TV_hr[dirty$TV_hr < 0] <- NA

# d. Recode factors to the right value
# Recode favourite_genre to "action", "comedy", "thriller", and "prefer not to say"
table(dirty$favourite_genre)
dirty$favourite_genre <- fct_recode(dirty$favourite_genre,
                                    action="actin",
                                    comedy="comdy",
                                    comedy="Comedy",
                                    thriller="Thriler",
                                    thriller="thrller",)

# Recode gender to "male" and "female"
table(dirty$gender)
dirty$gender  <- fct_recode(dirty$gender, 
                            female = "Female", 
                            female = "F", 
                            male = "Male",
                            male = "M")

# 2. For each of the variables, produce an appropriate plot to look at the data.
# a. Look at histograms for numeric variables
#sleep_hr
ggplot(dirty,aes(sleep_hr)) + geom_histogram(colour = 4, 
                                             fill = "white", 
                                             binwidth = 1) + ggtitle("sleep_hr histogram")
#TV_hr
ggplot(dirty,aes(TV_hr)) + geom_histogram(colour = 4, 
                                          fill = "white", 
                                          binwidth = 1) + ggtitle("TV_hr histogram")
#height
ggplot(dirty,aes(height)) + geom_histogram(colour = 4, 
                                           fill = "white", 
                                           binwidth = 1) + ggtitle("height histogram")
#weight
ggplot(dirty,aes(weight)) + geom_histogram(colour = 4, 
                                           fill = "white", 
                                           binwidth = 1) + ggtitle("weight histogram")

# b. Look at bar charts for categorical variables
#favourite_genre
ggplot(dirty,aes(favourite_genre)) + geom_bar(colour = 4, 
                                              fill = "white") + ggtitle("favourite_genre bar chart") 

#gender
ggplot(dirty,aes(gender)) + geom_bar(colour = 4, 
                                      fill = "white") + ggtitle("gender bar chart")

# 3.
# Quantitative variables
# - sleep_hr: unimodel and relatively symmetric
# - TV_hr: unimodel and right-skewed
# - height: unimodel and left-skewed
# - weight: unimodel and relatively symmetric

# Categorical variables
# - favourite_genre: comedy is the most common level
# - gender: male is the most common level

# 4. 
# function to get five-number summaries for quantitative variables
five_num_summary <- function(x) {
  min <- min(x, na.rm = TRUE)
  
  sorted <- sort(x)
  
  lower <- sorted[1:round(length(sorted)/2)]
  lower <- median(lower)
  
  median <- median(x, na.rm = TRUE)
  
  upper <- sorted[round((length(sorted)/2)+1):length(sorted)]
  upper <- median(upper)
  
  max <- max(x, na.rm = TRUE)
  
  five <- cbind(min, lower, median, upper, max)
  colnames(five) <- c("Min", "Lower-hinge", "Median", "Upper-hinge", "Max")
  return(five)
}
# Generate five-number summaries
# sleep_hr five-number summaries
five_num_summary(dirty$sleep_hr)

# TV_hr five-number summaries
five_num_summary(dirty$TV_hr)

# height five-number summaries
five_num_summary(dirty$height)

# weight five-number summaries
five_num_summary(dirty$weight)

# Generate frequency tables
# favourite_genre frequency tables
table(dirty$favourite_genre)

# gender frequency tables
table(dirty$gender)

# Missing values:
# sleep_hr: 2 NA's, the proportion of missing value is 1.31%
summary(dirty$sleep_hr)
sleep_hr_missing_p <- 2/153*100
sleep_hr_missing_p
# Participant 45 and 117 does not have value for sleep_hr
dirty$particiant_id[is.na(dirty$sleep_hr)]
dirty[45,]
dirty[117,]

# TV_hr: 11 NA's, the proportion of missing value is 7.20%
summary(dirty$TV_hr)
TV_hr_missing_p <- 11/153*100
TV_hr_missing_p
# Participant 82, 85, 94, 99, 103, 108, 124, 128, 137, 139, and 146 does not have value for TV_hr
dirty$particiant_id[is.na(dirty$TV_hr)]
dirty[82,]
dirty[85,]
dirty[94,]
dirty[99,]
dirty[103,]
dirty[108,]
dirty[124,]
dirty[128,]
dirty[137,]
dirty[139,]
dirty[146,]

# height: 5 NA's, the proportion of missing value is 3.27%
summary(dirty$height)
height_missing_p <- 5/153*100
height_missing_p
# Participant 9, 15, 19, 116, and 145 does not have value for height
dirty$particiant_id[is.na(dirty$height)]
dirty[9,]
dirty[15,]
dirty[19,]
dirty[116,]
dirty[145,]

# weight: 4 NA's, the proportion of missing value is 2.61%
summary(dirty$weight)
weight_missing_p <- 4/153*100
weight_missing_p
# Participant 15, 128, 145, and 151 does not have value for weight
dirty$particiant_id[is.na(dirty$weight)]
dirty[15,]
dirty[128,]
dirty[145,]
dirty[151,]

# 5.Export the cleaned data into a CSV file
directory <- getwd()
write_csv(dirty, paste(directory,'/A1_a1814824.csv', sep=""))