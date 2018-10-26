// Code your design here
// Code your design here
// Code your design here
// Code your design here
// Code your design here   


module datapath(reg_out,mplier, mcand, f_sel, prd_sel, ld, rst, dec, ans, prd_status, count_status);
  input dec;
  output [17:0]reg_out;
  input [1:0] f_sel, prd_sel;
  output [17:0] ans;
  output [2:0] prd_status;
  output count_status;
  input [2:0] ld,rst;
  input [7:0] mcand,mplier;
  wire [7:0] bus_y;
  wire [8:0] bus_x, bus_z,out_y;

  assign ans = reg_out;
  assign prd_status = reg_out[2:0];
  
  //register for count and associated function
  wire [3:0] count_in,count_out;
  mux_count mx1(count_in,dec,count_out,count_status);
  register_4 count_reg(count_out, count_in, 1, ld[0], rst[0]);
  
  //register for mcand
  register_8 mcand_reg(bus_y,mcand, 1, ld[1], rst[1]);

  //selecting y or 2*y // 0 selects y
  bit9_mux_2to1 mux(out_y, {bus_y[7],bus_y[7:0]}, {bus_y[7:0],1'b0}, f_sel[0]);
  
  //instance of alu
  alu alu1(bus_x, out_y[7:0], bus_z, f_sel);
  
  //register main and associated local function
  wire [17:0] reg_in, reg_out; 
  mux_prd sel_prd(reg_in, reg_out, mplier, bus_z, prd_sel);
  register_18 reg_main(reg_out, reg_in, 1, ld[2],rst[2]);
  assign bus_x = reg_out[17:9];
endmodule

//f_sel : 
// 00 : z <- X - Y
// 01 : z <- X - 2Y
// 10 : Z <- x + Y
// 11 : z <- X + 2Y



module alu(bus_x,bus_y,bus_z,f_sel);
  input[7:0] bus_y;
  input[8:0] bus_x;
  input [1:0] f_sel;
  output [8:0] bus_z;
  
  
  wire [8:0] out_y,out_sum,out_sub;
  add_9 ad(out_sum, bus_x, {1'b0,bus_y});
  sub_9 sb(out_sub, bus_x, {1'b0,bus_y});
  
  //selecting y or 2*y // 0 selects y
 // bit9_mux_2to1 mux(out_y, {bus_y[7],bus_y[7:0]}, {bus_y[7:0],1'b0}, f_sel[0]);
  
  
  //selecting add or sub o selects out_sum
  bit9_mux_2to1 mux2(bus_z,out_sub , out_sum,  f_sel[1]);
endmodule

module bit9_mux_2to1(out,x,y,sel);
  input [8:0] x,y;
  input sel;
  output [8:0] out;

          mux2to1 m0(y[0],x[0],sel,out[0]);
          mux2to1 m1(y[1],x[1],sel,out[1]);
          mux2to1 m2(y[2],x[2],sel,out[2]);
          mux2to1 m3(y[3],x[3],sel,out[3]);
          mux2to1 m4(y[4],x[4],sel,out[4]);
          mux2to1 m5(y[5],x[5],sel,out[5]);
          mux2to1 m6(y[6],x[6],sel,out[6]);
          mux2to1 m7(y[7],x[7],sel,out[7]);
          mux2to1 m8(y[8],x[8],sel,out[8]);

endmodule

// mux 2to1
module mux2to1(a,b,sel,out);
	input a,b,sel;
	output out;
	tri out;
	bufif1 (out,a,sel);
	bufif0 (out,b,sel);
endmodule

//a-b
module sub_9(sub, a, b);
  input [8:0] a,b;
  output [8:0] sub;
  wire [8:0] nb;         //stores not of x
  wire [8:0] notb_inc;

  //loop to get 1s complement of x

      not n0(nb[0],b[0]);
      not n1(nb[1],b[1]);
      not n2(nb[2],b[2]);
      not n3(nb[3],b[3]);
      not n4(nb[4],b[4]);
      not n5(nb[5],b[5]);
      not n6(nb[6],b[6]);
      not n7(nb[7],b[7]);
      not n8(nb[8],b[8]);


//adding 1 to 1s complement of x to get 2s complement
  add_9 a1(notb_inc,nb,1);
  add_9 a2(sub,notb_inc,a);
endmodule


module add_9(sum,a,b);
  input [8:0] a,b;
  output [8:0] sum;

  wire [9:0]carry;

  assign carry[0] = 0;
  

      fa f0(sum[0],carry[1],a[0],b[0],carry[0]);
      fa f1(sum[1],carry[2],a[1],b[1],carry[1]);
      fa f2(sum[2],carry[3],a[2],b[2],carry[2]);
      fa f3(sum[3],carry[4],a[3],b[3],carry[3]);
      fa f4(sum[4],carry[5],a[4],b[4],carry[4]);
      fa f5(sum[5],carry[6],a[5],b[5],carry[5]);
      fa f6(sum[6],carry[7],a[6],b[6],carry[6]);
      fa f7(sum[7],carry[8],a[7],b[7],carry[7]);
      fa f8(sum[8],carry[9],a[8],b[8],carry[8]);

	
endmodule



module fa(s,co,a,b,ci);
    output s,co;
    input a,b,ci;
    wire n1,n2,n3;

    xor u1(s,a,b,ci);
    and u2(n1,a,b);
    and u3(n2,b,ci);
    and u4(n3,a,ci);
    or u5(co,n1,n2,n3);

endmodule


//mux 4to1
module mux4to1(a,sel,out);
	input [3:0] a;
	input [1:0] sel;
	output out;
	wire mux[2:0];

	mux2to1 m1 (a[3],a[2],sel[0],mux[1]),
	        m2 (a[1],a[0],sel[0],mux[0]),
	        m3 (mux[1],mux[0],sel[1],out);
endmodule

// register function prd top module
module mux_prd(out,regout,mplier,z,sel);
  output [17:0]out;
  input [1:0]sel;
  input [17:0]regout;
  input [7:0]mplier;
  input [8:0]z;
  wire [17:0] w0,w1,w2,w3;		// w0:load multiplier		w1:reset		w2:rshift by 2		w3:answer rshift by 2
  
  		assign w0[0] = 1'b0;
      	assign w0[1] = mplier[0];
      	assign w0[2] = mplier[1];
      	assign w0[3] = mplier[2];
      	assign w0[4] = mplier[3];
      	assign w0[5] = mplier[4];
      	assign w0[6] = mplier[5];
      	assign w0[7] = mplier[6];
      	assign w0[8] = mplier[7];
      	assign w0[9] = 1'b0;
		assign w0[10] = 1'b0;
		assign w0[11] = 1'b0;
		assign w0[12] = 1'b0;
		assign w0[13] = 1'b0;
		assign w0[14] = 1'b0;
		assign w0[15] = 1'b0;
		assign w0[16] = 1'b0;
		assign w0[17] = 1'b0;
  
  		assign w1 = 17'b0;
  	
      	assign w2[0] = regout[2];
      	assign w2[1] = regout[3];
      	assign w2[2] = regout[4];
      	assign w2[3] = regout[5];
      	assign w2[4] = regout[6];
      	assign w2[5] = regout[7];
      	assign w2[6] = regout[8];
      	assign w2[7] = regout[9];
     	assign w2[8] = regout[10];
      	assign w2[9] = regout[11];
      	assign w2[10] = regout[12];
      	assign w2[11] = regout[13];
      	assign w2[12] = regout[14];
      	assign w2[13] = regout[15];
      	assign w2[14] = regout[16];
      	assign w2[15] = regout[17];
  		assign w2[16]= regout[17];
		assign w2[17]= regout[17];

      	assign w3[0] = regout[2];
      	assign w3[1] = regout[3];
      	assign w3[2] = regout[4];
      	assign w3[3] = regout[5];
      	assign w3[4] = regout[6];
      	assign w3[5] = regout[7];
      	assign w3[6] = regout[8];
		assign w3[7] = z[0];
		assign w3[8] = z[1];
		assign w3[9] = z[2];
		assign w3[10] = z[3];
		assign w3[11] = z[4];
		assign w3[12] = z[5];
		assign w3[13] = z[6];
		assign w3[14] = z[7];
		assign w3[15] = z[8];
	  	assign w3[16] = z[8];
  		assign w3[17] = z[8];


      mux4to1 m0({w3[0],w2[0],w1[0],w0[0]},sel,out[0]);
      mux4to1 m1({w3[1],w2[1],w1[1],w0[1]},sel,out[1]);
      mux4to1 m2({w3[2],w2[2],w1[2],w0[2]},sel,out[2]);
      mux4to1 m3({w3[3],w2[3],w1[3],w0[3]},sel,out[3]);
      mux4to1 m4({w3[4],w2[4],w1[4],w0[4]},sel,out[4]);
      mux4to1 m5({w3[5],w2[5],w1[5],w0[5]},sel,out[5]);
      mux4to1 m6({w3[6],w2[6],w1[6],w0[6]},sel,out[6]);
      mux4to1 m7({w3[7],w2[7],w1[7],w0[7]},sel,out[7]);
      mux4to1 m8({w3[8],w2[8],w1[8],w0[8]},sel,out[8]);
      mux4to1 m9({w3[9],w2[9],w1[9],w0[9]},sel,out[9]);
      mux4to1 m10({w3[10],w2[10],w1[10],w0[10]},sel,out[10]);
      mux4to1 m11({w3[11],w2[11],w1[11],w0[11]},sel,out[11]);
      mux4to1 m12({w3[12],w2[12],w1[12],w0[12]},sel,out[12]);
      mux4to1 m13({w3[13],w2[13],w1[13],w0[13]},sel,out[13]);
      mux4to1 m14({w3[14],w2[14],w1[14],w0[14]},sel,out[14]);
      mux4to1 m15({w3[15],w2[15],w1[15],w0[15]},sel,out[15]);
      mux4to1 m16({w3[16],w2[16],w1[16],w0[16]},sel,out[16]);
      mux4to1 m17({w3[17],w2[17],w1[17],w0[17]},sel,out[17]);

  
endmodule

// register function count top module
module mux_count(out,sel,in,status);
  output [3:0]out;
  input sel;
  output status;
  input [3:0]in;
  wire [3:0] w0,w1;	//w0:count=4		w1:count-=1
  assign w1[3]=0;
  assign w1[2]=in[3];
  assign w1[1]=in[2];
  assign w1[0]=in[1];
  
  assign w0[3]=1'b1;
  assign w0[2]=1'b0;
  assign w0[1]=1'b0;
  assign w0[0]=1'b0;
  

        mux2to1 m0(w1[0],w0[0],sel,out[0]);
        mux2to1 m1(w1[1],w0[1],sel,out[1]);
        mux2to1 m2(w1[2],w0[2],sel,out[2]);
        mux2to1 m3(w1[3],w0[3],sel,out[3]);

  status_count jjj(in,status);
endmodule

// status detector for count==0?
module status_count(regout,out);
  output out;
  wire w;
  input [3:0]regout;
  or o1(w,regout[3],regout[2],regout[1],regout[0]);
  not nl(out,w);
endmodule


// structural code for register_4
module register_4(out,in,load,clk,rst);
	output [3:0] out;
	input load,clk,rst;
	input [3:0] in;

			dff d0(out[0],in[0],clk,rst);
			dff d1(out[1],in[1],clk,rst);
			dff d2(out[2],in[2],clk,rst);
			dff d3(out[3],in[3],clk,rst);

endmodule

// structural code for register_8
module register_8(out,in,load,clk,rst);
	output [7:0] out;
	input load,clk,rst;
	input [7:0] in;

          dff d0(out[0],in[0],clk,rst);
          dff d1(out[1],in[1],clk,rst);
          dff d2(out[2],in[2],clk,rst);
          dff d3(out[3],in[3],clk,rst);
          dff d4(out[4],in[4],clk,rst);
          dff d5(out[5],in[5],clk,rst);
          dff d6(out[6],in[6],clk,rst);
          dff d7(out[7],in[7],clk,rst);

endmodule

// structural code for register_18
module register_18(out,in,load,clk,rst);
	output [17:0] out;
	input load,clk,rst;
	input [17:0] in;


          dff d0(out[0],in[0],clk,rst);
          dff d1(out[1],in[1],clk,rst);
          dff d2(out[2],in[2],clk,rst);
          dff d3(out[3],in[3],clk,rst);
          dff d4(out[4],in[4],clk,rst);
          dff d5(out[5],in[5],clk,rst);
          dff d6(out[6],in[6],clk,rst);
          dff d7(out[7],in[7],clk,rst);
		  dff d8(out[8],in[8],clk,rst);
		  dff d9(out[9],in[9],clk,rst);
          dff d10(out[10],in[10],clk,rst);
          dff d11(out[11],in[11],clk,rst);
          dff d12(out[12],in[12],clk,rst);
          dff d13(out[13],in[13],clk,rst);
          dff d14(out[14],in[14],clk,rst);
          dff d15(out[15],in[15],clk,rst);
          dff d16(out[16],in[16],clk,rst);
          dff d17(out[17],in[17],clk,rst);

endmodule

// Code your design here
module dff_latch(Q,D,CLK,reset);
  output Q;
  input D,CLK,reset;
  wire nr,inp,X,Y,Q_BAR;
  not r1(nr,reset);
  and r2(inp,D,nr);
  nand U1 (X,inp,CLK) ;
  nand U2 (Y,X,CLK) ;
  nand U3 (Q,Q_BAR,X);
  nand U4 (Q_BAR,Q,Y);  
endmodule

module dff(out,in,clk,rst);
  output out;
  input in,clk,rst;
  wire Q1;
  dff_latch d1(Q1,in,clk,rst);
  dff_latch d2(out,Q1,~clk,rst);
  
endmodule
// Code your testbench here
// or browse Examples
module testbench;
  wire [17:0]ans;
  reg [7:0] mplier,mcand;
  reg clk, rst, go;
  wire over;
  wire [1:0] state;
  multiplier m(state,ans,over,mplier,mcand,clk,rst,go);
  initial begin
    mplier = 120;
    mcand = 3;
    go=0;
    rst=1;
    #5
    
    rst=0;
    go=1;
    
    #60
    $display("%d * %d = %d",mplier,mcand,ans[16:1]);
    #1
   // go=0;
    #10
    $display("Go=0 %d * %d = %d",mplier,mcand,ans[16:1]);
  end
  integer t;
  initial begin
    clk=0;
    t=0;
    while(t<80) begin
      #1
     	// $display("state = %d,	over = %d",state,over);
      clk=~clk;
      t=t+1;
    end
  end
 
endmodule
