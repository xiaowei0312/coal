create table t_coal_detection(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    data_000 varchar(20),
    data_001 varchar(20),
    data_002 varchar(20),
    
    data_010 varchar(20),
    data_011 varchar(20),
    data_012 varchar(20),
    
    data_020 varchar(20),
    data_021 varchar(20),
    data_022 varchar(20),
    
    data_030 varchar(20),
    data_031 varchar(20),
    data_032 varchar(20),
    
    data_100 varchar(20),
    data_101 varchar(20),
    data_102 varchar(20),
    data_103 varchar(20),
    
    data_200 varchar(20),
    data_201 varchar(20),
    data_202 varchar(20),
    data_203 varchar(20),
    data_204 varchar(20),
    data_205 varchar(20),
    
    data_210 varchar(20),
    data_211 varchar(20),
    data_212 varchar(20),
    data_213 varchar(20),
    data_214 varchar(20),
    data_215 varchar(20),
    
    data_220 varchar(20),
    data_221 varchar(20),
    data_222 varchar(20),
    data_223 varchar(20),
    data_224 varchar(20),
    data_225 varchar(20),
    data_1001 varchar(20),
    data_1002 varchar(20),
    
    data_300 varchar(20),
    data_301 varchar(20),
    data_302 varchar(20),
    data_303 varchar(20),
    data_304 varchar(20),
    data_305 varchar(20),
    data_306 varchar(20),

    add_time DATETIME DEFAULT (datetime('now','localtime')),
    lmt_time TIMESTAMP DEFAULT (datetime('now','localtime')),
    is_deleted int DEFAULT 0,
    sms_flag int DEFAULT 0
);

create table t_coal_sms(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    objnames  varchar(100),
    coal_detection_id INTEGER,
    foreign key(coal_detection_id) references t_coal_detection(id)
);

create table t_user(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(50),
    alias VARCHAR(50),
    phone VARCHAR(20),
    add_time DATETIME DEFAULT (datetime('now','localtime')),
    lmt_time TIMESTAMP DEFAULT (datetime('now','localtime')),
    is_deleted int DEFAULT 0
);

INSERT INTO t_user values(NULL,"admin","111111","³Â¼Ò±¤À¤Íú»¯Ñé","18303491642",datetime('now','localtime'),datetime('now','localtime'),0);
