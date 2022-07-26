DROP DATABASE IF EXISTS theatre;
CREATE DATABASE theatre;
USE theatre;

CREATE TABLE Users (
    user_id INT NOT NULL AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL,
    password BINARY(32) NOT NULL,
    email VARCHAR(50) NOT NULL,


    PRIMARY KEY (user_id),
    CONSTRAINT username_not_unique UNIQUE (username)
);

CREATE TABLE Sections (
    section_id INT NOT NULL AUTO_INCREMENT,
    section_name VARCHAR(10),

    PRIMARY KEY (section_id),
    CONSTRAINT section_not_unique UNIQUE (section_name)
);

CREATE TABLE Seats (
    seat_id INT NOT NULL AUTO_INCREMENT,
    seat_number INT NOT NULL,
    section_id INT NOT NULL,

    PRIMARY KEY (seat_id),
    CONSTRAINT fk_sectionid_to_seat FOREIGN KEY (section_id) REFERENCES Sections (section_id)
);

CREATE TABLE Plays (
    play_id INT NOT NULL AUTO_INCREMENT,
    play_name VARCHAR(50) NOT NULL,

    PRIMARY KEY (play_id),
    CONSTRAINT play_name_not_unique UNIQUE (play_name)
);

CREATE TABLE Shows (
    show_id INT NOT NULL AUTO_INCREMENT,
    date DATE NOT NULL,
    time TIME NOT NULL,
    play_id INT NOT NULL,

    PRIMARY KEY (show_id),
    CONSTRAINT fk_playid_to_show FOREIGN KEY (play_id) REFERENCES Plays (play_id)
);

CREATE TABLE Bookings (
    booking_id INT NOT NULL AUTO_INCREMENT,
    user_id INT NOT NULL,
    seat_id INT NOT NULL,
    show_id INT NOT NULL,

    PRIMARY KEY (booking_id),
    CONSTRAINT fk_userid_to_booking FOREIGN KEY (user_id) REFERENCES Users (user_id) ON DELETE CASCADE,
    CONSTRAINT fk_seatid_to_booking FOREIGN KEY (seat_id) REFERENCES Seats (seat_id) ON DELETE CASCADE,
    CONSTRAINT fk_showid_to_booking FOREIGN KEY (show_id) REFERENCES Shows (show_id) ON DELETE CASCADE
);

/* Function */
/* User related */
DELIMITER //
CREATE PROCEDURE sign_up (
    IN username_ VARCHAR(50), email_ VARCHAR(50), password_ VARCHAR(30)
)
BEGIN
    INSERT INTO Users (username, email, password) VALUES (username_, email_, UNHEX(SHA2(CONCAT('SA', password_, 'LT'), 256)));
    CALL login(username_, password_);
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE login (
    IN username_ VARCHAR(50), password_ VARCHAR(30)
)
BEGIN
    SELECT * FROM Users WHERE username = username_ AND password = UNHEX(SHA2(CONCAT('SA', password_, 'LT'), 256));
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE book (
    IN user_id_ INT, seat_id_ INT, show_id_ INT
)
BEGIN
    INSERT INTO Bookings (user_id, seat_id, show_id) VALUES (user_id_, seat_id_, show_id_);
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE view_bookings (
    IN user_id_ INT
)
BEGIN
    SELECT play_name, date, time, section_name, seat_number from Bookings
    INNER JOIN Seats ON Seats.seat_id = Bookings.seat_id
    INNER JOIN Sections ON Sections.section_id = Seats.section_id
    INNER JOIN Shows ON Shows.show_id = Bookings.show_id
    INNER JOIN Plays ON Plays.play_id = Shows.play_id
    WHERE user_id = user_id_
    AND ((date >= DATE(CURRENT_TIMESTAMP) AND time >= TIME(CURRENT_TIMESTAMP))
        OR (DATE(CURRENT_TIMESTAMP) - date <= 3))
    ORDER BY date ASC, time ASC;
END //
DELIMITER ;

/* Shows related */
DELIMITER //
CREATE PROCEDURE add_section (
    IN section_name_ VARCHAR(10)
)
BEGIN
    INSERT INTO Sections (section_name) VALUES (section_name_);
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE add_seat (
    IN seat_number_ INT, IN section_id_ INT
)
BEGIN
    INSERT INTO Seats (seat_number, section_id) VALUES (seat_number_, section_id_);
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE add_show (
    IN date_ DATE, IN time_ TIME, IN play_id_ INT
)
BEGIN
    INSERT INTO Shows (date, time, play_id) VALUES (date_, time_, play_id_);
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE add_play (
    IN play_name_ VARCHAR(50)
)
BEGIN
    INSERT INTO Plays (play_name) VALUES (play_name_);
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE get_all_sections (
)
BEGIN
    SELECT * FROM Sections;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE get_current_show (
)
BEGIN
    SELECT show_id, play_name, date, time from Shows
    INNER JOIN Plays ON Plays.play_id = Shows.play_id
    AND date >= DATE(CURRENT_TIMESTAMP)
    ORDER BY date ASC, time ASC;
END //
DELIMITER ;

DELIMITER //
CREATE PROCEDURE get_available_seats (
    IN show_id_ INT
)
BEGIN
    SELECT Sections.section_id, section_name, Seats.seat_id, seat_number from Seats
    INNER JOIN Sections ON Sections.section_id = Seats.section_id
    WHERE seat_id NOT IN (SELECT seat_id FROM Bookings WHERE show_id = show_id_)
    ORDER BY section_name ASC, seat_number ASC;
END //
DELIMITER ;

/* Task 1.5 */
DELIMITER //
CREATE PROCEDURE booked_on_20june2022 (
)
BEGIN
    SELECT DISTINCT section_name, seat_number FROM Bookings
    INNER JOIN Shows ON Shows.show_id = Bookings.show_id
    INNER JOIN Seats ON Seats.seat_id = Bookings.seat_id
    INNER JOIN Sections ON Sections.section_id = Seats.section_id
    WHERE date = '2022-06-20';
END //
DELIMITER ;


/* Mock database */
CALL sign_up ('test01', 'test01@gmail.com', 'pass01');
CALL sign_up ('test02', 'test02@gmail.com', 'pass02');
CALL sign_up ('test03', 'test03@gmail.com', 'pass03');

CALL add_section ('A');
CALL add_section ('B');
CALL add_section ('C');

CALL add_seat (1,1);
CALL add_seat (2,1);
CALL add_seat (3,1);
CALL add_seat (1,2);
CALL add_seat (2,2);
CALL add_seat (3,2);
CALL add_seat (1,3);
CALL add_seat (2,3);
CALL add_seat (3,3);

CALL add_play ('Frozen');
CALL add_play ('Lion King');
CALL add_play ('Broadway');

CALL add_show ('2022-06-20', '13:00:00', 1);
CALL add_show ('2022-06-20', '15:00:00', 3);
CALL add_show ('2022-06-25', '17:00:00', 2);
CALL add_show ('2022-06-27', '14:00:00', 1);

CALL book (1, 1, 1);
CALL book (1, 3, 4);
CALL book (2, 2, 1);
CALL book (2, 7, 2);
CALL book (2, 6, 2);
CALL book (3, 5, 1);
CALL book (1, 9, 1);