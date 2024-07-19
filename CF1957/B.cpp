module ALU(
    input wire [15:0] x,
    input wire [15:0] y,
    input wire zx, nx, zy, ny, f, no,
    output wire [15:0] o,
    output wire zr, ng
);

wire [15:0] zx_o; wire [15:0] mul_zx;
assign mul_zx = {16{zx}};
assign zx_o = x&~mul_zx;
wire [15:0] nx_o; wire [15:0] mul_nx;
assign mul_nx = {16{nx}};
assign nx_o = zx_o^mul_nx;

wire [15:0] zy_o; wire [15:0] mul_zy;
assign mul_zy = {16{zy}};
assign zy_o = y&~mul_zy;
wire [15:0] ny_o; wire [15:0] mul_ny;
assign mul_ny = {16{ny}};
assign ny_o = zy_o^mul_ny;

wire [15:0] f_o; wire [15:0] mul_f;
assign mul_f = {16{f}};
assign f_o = ~mul_f&(nx_o&ny_o) | mul_f&(nx_o+ny_o);
wire [15:0] mul_no;
assign mul_no = {16{no}};
assign o = f_o^mul_no;

assign zr = ~o[15]&~o[14]&~o[13]&~o[12]&~o[11]&~o[10]&~o[9]&~o[8]&~o[7]&~o[6]&~o[5]&~o[4]&~o[3]&~o[2]&~o[1]&~o[0];
assign ng = o[15];

endmodule