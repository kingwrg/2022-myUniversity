library(tidyverse)

data("mpg")
mpg

table(mpg$manufacturer)
filter(mpg, manufacturer == "audi")
filter(mpg, manufacturer == "audi", year <= 2000)
filter(mpg, drv == "f", cyl == 6)
q3 <- filter(mpg, manufacturer == c("audi", "dodge"))

select(mpg, model, trans)
select(mpg, contains("dis"))
select(mpg, displ:cyl)

mutate(mpg, cty_km_l = cty * 0.425144)
mpg
mpg  <- mutate(mpg, cty_km_l = cty * 0.425144)

mpg_audi  <- filter(mpg, manufacturer == "audi")
mpg_trans_cty  <- select(mpg_audi, trans:cty)
mpg_trans_cty_km  <- mutate(mpg_trans_cty, cty_km_l = cty * 0.425144)
mpg_trans_cty_km

mpg %>% 
  filter(manufacturer == "audi") %>% 
  select(trans:cty) %>% 
  mutate(cty_km_l = cty * 0.425144)

mpg %>% 
  filter(manufacturer == "audi", year <= 2000) %>% 
  select(manufacturer, model, displ, year, cty) %>% 
  mutate(cty_km_l = cty * 0.425144) %>% 
  filter(cty_km_l > 8)

mpg %>% 
  group_by(manufacturer) %>% 
  summarise(mean = mean(cty, na.rm = TRUE))

mpg %>% 
  group_by(manufacturer) %>% 
  summarise(mean = mean(cty, na.rm = TRUE), 
            n = n(), 
            sd = sd(cty, na.rm = TRUE))

source("get_lwr_ci.R")
get_lwr_ci(mpg$cty)

source("get_upr_ci.R")
get_upr_ci(mpg$cty)

mpg %>% 
  group_by(manufacturer) %>%
  filter(manufacturer=="honda") %>%
  summarise(upr=get_upr_ci(cty),
            lwr=get_lwr_ci(cty))
