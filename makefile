all:svr cli
svr:svr.cpp
	g++ $^ -o $@

cli:cli.cpp
	g++ $^ -o $@

