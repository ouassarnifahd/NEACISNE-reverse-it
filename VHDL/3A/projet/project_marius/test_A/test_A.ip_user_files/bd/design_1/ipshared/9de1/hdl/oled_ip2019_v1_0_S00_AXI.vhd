library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity oled_ip2019_v1_0_S00_AXI is
	generic (
		-- Users to add parameters here

		-- User parameters ends
		-- Do not modify the parameters beyond this line

		-- Width of S_AXI data bus
		C_S_AXI_DATA_WIDTH	: integer	:= 32;
		-- Width of S_AXI address bus
		C_S_AXI_ADDR_WIDTH	: integer	:= 7
	);
	port (
		-- Users to add ports here
        SDIN : out std_logic;
        SCLK : out std_logic;
        DC : out std_logic;
        RES : out std_logic;
        VBAT : out std_logic;
        VDD : out std_logic;
		-- User ports ends
		-- Do not modify the ports beyond this line

		-- Global Clock Signal
		S_AXI_ACLK	: in std_logic;
		-- Global Reset Signal. This Signal is Active LOW
		S_AXI_ARESETN	: in std_logic;
		-- Write address (issued by master, acceped by Slave)
		S_AXI_AWADDR	: in std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
		-- Write channel Protection type. This signal indicates the
    		-- privilege and security level of the transaction, and whether
    		-- the transaction is a data access or an instruction access.
		S_AXI_AWPROT	: in std_logic_vector(2 downto 0);
		-- Write address valid. This signal indicates that the master signaling
    		-- valid write address and control information.
		S_AXI_AWVALID	: in std_logic;
		-- Write address ready. This signal indicates that the slave is ready
    		-- to accept an address and associated control signals.
		S_AXI_AWREADY	: out std_logic;
		-- Write data (issued by master, acceped by Slave) 
		S_AXI_WDATA	: in std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		-- Write strobes. This signal indicates which byte lanes hold
    		-- valid data. There is one write strobe bit for each eight
    		-- bits of the write data bus.    
		S_AXI_WSTRB	: in std_logic_vector((C_S_AXI_DATA_WIDTH/8)-1 downto 0);
		-- Write valid. This signal indicates that valid write
    		-- data and strobes are available.
		S_AXI_WVALID	: in std_logic;
		-- Write ready. This signal indicates that the slave
    		-- can accept the write data.
		S_AXI_WREADY	: out std_logic;
		-- Write response. This signal indicates the status
    		-- of the write transaction.
		S_AXI_BRESP	: out std_logic_vector(1 downto 0);
		-- Write response valid. This signal indicates that the channel
    		-- is signaling a valid write response.
		S_AXI_BVALID	: out std_logic;
		-- Response ready. This signal indicates that the master
    		-- can accept a write response.
		S_AXI_BREADY	: in std_logic;
		-- Read address (issued by master, acceped by Slave)
		S_AXI_ARADDR	: in std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
		-- Protection type. This signal indicates the privilege
    		-- and security level of the transaction, and whether the
    		-- transaction is a data access or an instruction access.
		S_AXI_ARPROT	: in std_logic_vector(2 downto 0);
		-- Read address valid. This signal indicates that the channel
    		-- is signaling valid read address and control information.
		S_AXI_ARVALID	: in std_logic;
		-- Read address ready. This signal indicates that the slave is
    		-- ready to accept an address and associated control signals.
		S_AXI_ARREADY	: out std_logic;
		-- Read data (issued by slave)
		S_AXI_RDATA	: out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
		-- Read response. This signal indicates the status of the
    		-- read transfer.
		S_AXI_RRESP	: out std_logic_vector(1 downto 0);
		-- Read valid. This signal indicates that the channel is
    		-- signaling the required read data.
		S_AXI_RVALID	: out std_logic;
		-- Read ready. This signal indicates that the master can
    		-- accept the read data and response information.
		S_AXI_RREADY	: in std_logic
	);
end oled_ip2019_v1_0_S00_AXI;

architecture arch_imp of oled_ip2019_v1_0_S00_AXI is

	-- AXI4LITE signals
	signal axi_awaddr	: std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
	signal axi_awready	: std_logic;
	signal axi_wready	: std_logic;
	signal axi_bresp	: std_logic_vector(1 downto 0);
	signal axi_bvalid	: std_logic;
	signal axi_araddr	: std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
	signal axi_arready	: std_logic;
	signal axi_rdata	: std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal axi_rresp	: std_logic_vector(1 downto 0);
	signal axi_rvalid	: std_logic;

	-- Example-specific design signals
	-- local parameter for addressing 32 bit / 64 bit C_S_AXI_DATA_WIDTH
	-- ADDR_LSB is used for addressing 32/64 bit registers/memories
	-- ADDR_LSB = 2 for 32 bits (n downto 2)
	-- ADDR_LSB = 3 for 64 bits (n downto 3)
	constant ADDR_LSB  : integer := (C_S_AXI_DATA_WIDTH/32)+ 1;
	constant OPT_MEM_ADDR_BITS : integer := 4;
	------------------------------------------------
	---- Signals for user logic register space example
	--------------------------------------------------
	---- Number of Slave Registers 17
	signal slv_reg0	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg1	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg2	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg3	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg4	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg5	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg6	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg7	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg8	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg9	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg10	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg11	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg12	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg13	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg14	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg15	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg16	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal slv_reg_rden	: std_logic;
	signal slv_reg_wren	: std_logic;
	signal reg_data_out	:std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
	signal byte_index	: integer;
	signal aw_en	: std_logic;

    
    type states is ( idle, vddon, wait1, dispoff, setclockdiv1, setclockdiv2,
                multiplex1, multiplex2, chargepump1, chargepump2, precharge1,
                precharge2, vcomh1, vcomh2, dispcontrast1, dispcontrast2,
                invertdisp1, invertdisp2, comconfig1, comconfig2, vbaton,
                wait3, reseton, wait2, resetoff, waitrequest, cleardc, setpage, 
                pagenum,leftcolumn1, leftcolumn2, setdc, clearscreen, readregisters,
                updatescreen, sendchar1, sendchar2, sendchar3, sendchar4,
                 sendchar5, sendchar6, sendchar7, sendchar8, readmem, readmem2,
                 transition1, transition2, transition3, transition4, transition5
                 );    -- 50 états
                 
    signal current_state : states := idle;
    signal after_state : states;
    signal after_page_state : states;
    signal after_char_state : states;
    signal after_update_state : states;
    
    type oled_mem is array (0 to 3, 0 to 15) of std_logic_vector(7 downto 0);
    signal current_screen : oled_mem;
    
    signal temp_dc : std_logic := '0';
    signal temp_res : std_logic := '1';
    signal temp_vbat : std_logic := '1';
    signal temp_vdd : std_logic := '1';
    
    signal temp_delay_ms : std_logic_vector(11 downto 0);
    signal temp_delay_en : std_logic := '0';
    signal temp_delay_fin : std_logic;
    
    signal temp_spi_en : std_logic := '0';
    signal temp_spi_data : std_logic_vector(7 downto 0):= x"00";
    signal temp_spi_fin : std_logic;
    
    signal temp_char : std_logic_vector(7 downto 0);
    signal temp_addr : std_logic_vector(10 downto 0);
    signal temp_dout : std_logic_vector(7 downto 0);
    signal temp_page : std_logic_vector(1 downto 0);
    signal temp_index : std_logic_vector(3 downto 0);
    
    signal init_first_r : std_logic := '1';
    signal clear_screen_i : std_logic := '1';
    signal ready : std_logic := '0';
    
    signal rst_internal : std_logic := '1';
    signal count : std_logic_vector(11 downto 0):= x"000";
    signal rst_in : std_logic;
    signal rst : std_logic := '0'; 
    signal j : integer := 0;
    signal i : integer := 0;
    
    signal display_c : std_logic;
    signal clear_c : std_logic;
    
    component SpiCtrl is
        Port ( 
               CLK         : in  STD_LOGIC; --System CLK (100MHz)
               RST         : in  STD_LOGIC; --Global RST (Synchronous)
               SPI_EN     : in  STD_LOGIC; --SPI block enable pin
               SPI_DATA : in  STD_LOGIC_VECTOR (7 downto 0); --Byte to be sent
               SDO         : out STD_LOGIC; --SPI data out
               S_CLK     : out STD_LOGIC; --SPI clock
               SPI_FIN    : out STD_LOGIC);--SPI finish flag
    end component;
    
    component Delay is
        Port ( 
                CLK             : in  STD_LOGIC; --System CLK
                RST         : in STD_LOGIC;  --Global RST (Synchronous)
                DELAY_MS     : in  STD_LOGIC_VECTOR (11 downto 0); --Amount of ms to delay
                DELAY_EN     : in  STD_LOGIC; --Delay block enable
                DELAY_FIN     : out  STD_LOGIC); --Delay finish flag
    end component;
    
    component   charlib is
        Port (
                CLKA : in std_logic;
                ADDRA : in std_logic_vector(10 downto 0);
                DOUTA : out std_logic_vector(7 downto 0));
    end component;
                 
     

begin
    
DC <= temp_dc;
RES <= temp_res;
VBAT <= temp_vbat;
VDD <= temp_vdd;

temp_delay_ms <= x"074" when (after_state = dispcontrast1) else x"014";

rst_in <= (rst or rst_internal);

display_c <= slv_reg16(0);
clear_c <= slv_reg16(1);

u1:SpiCtrl port map(
    clk => s_axi_aclk,
    rst => rst_in,
    spi_en => temp_spi_en,
    spi_data => temp_spi_data,
    sdo => sdin,
    S_CLK => sclk,
    spi_fin => temp_spi_fin
    );
    
u2:Delay port map (
    clk => s_axi_aclk,
    rst => rst_in,
    delay_ms => temp_delay_ms,
    delay_en => temp_delay_en,
    delay_fin => temp_delay_fin
    );
    
u3:charlib port map (
    clka => s_axi_aclk,
    addra => temp_addr,
    douta => temp_dout
    );
    
	-- I/O Connections assignments

	S_AXI_AWREADY	<= axi_awready;
	S_AXI_WREADY	<= axi_wready;
	S_AXI_BRESP	<= axi_bresp;
	S_AXI_BVALID	<= axi_bvalid;
	S_AXI_ARREADY	<= axi_arready;
	S_AXI_RDATA	<= axi_rdata;
	S_AXI_RRESP	<= axi_rresp;
	S_AXI_RVALID	<= axi_rvalid;
	-- Implement axi_awready generation
	-- axi_awready is asserted for one S_AXI_ACLK clock cycle when both
	-- S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_awready is
	-- de-asserted when reset is low.

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_awready <= '0';
	      aw_en <= '1';
	    else
	      if (axi_awready = '0' and S_AXI_AWVALID = '1' and S_AXI_WVALID = '1' and aw_en = '1') then
	        -- slave is ready to accept write address when
	        -- there is a valid write address and write data
	        -- on the write address and data bus. This design 
	        -- expects no outstanding transactions. 
	        axi_awready <= '1';
	        elsif (S_AXI_BREADY = '1' and axi_bvalid = '1') then
	            aw_en <= '1';
	        	axi_awready <= '0';
	      else
	        axi_awready <= '0';
	      end if;
	    end if;
	  end if;
	end process;

	-- Implement axi_awaddr latching
	-- This process is used to latch the address when both 
	-- S_AXI_AWVALID and S_AXI_WVALID are valid. 

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_awaddr <= (others => '0');
	    else
	      if (axi_awready = '0' and S_AXI_AWVALID = '1' and S_AXI_WVALID = '1' and aw_en = '1') then
	        -- Write Address latching
	        axi_awaddr <= S_AXI_AWADDR;
	      end if;
	    end if;
	  end if;                   
	end process; 

	-- Implement axi_wready generation
	-- axi_wready is asserted for one S_AXI_ACLK clock cycle when both
	-- S_AXI_AWVALID and S_AXI_WVALID are asserted. axi_wready is 
	-- de-asserted when reset is low. 

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_wready <= '0';
	    else
	      if (axi_wready = '0' and S_AXI_WVALID = '1' and S_AXI_AWVALID = '1' and aw_en = '1') then
	          -- slave is ready to accept write data when 
	          -- there is a valid write address and write data
	          -- on the write address and data bus. This design 
	          -- expects no outstanding transactions.           
	          axi_wready <= '1';
	      else
	        axi_wready <= '0';
	      end if;
	    end if;
	  end if;
	end process; 

	-- Implement memory mapped register select and write logic generation
	-- The write data is accepted and written to memory mapped registers when
	-- axi_awready, S_AXI_WVALID, axi_wready and S_AXI_WVALID are asserted. Write strobes are used to
	-- select byte enables of slave registers while writing.
	-- These registers are cleared when reset (active low) is applied.
	-- Slave register write enable is asserted when valid address and data are available
	-- and the slave is ready to accept the write address and write data.
	slv_reg_wren <= axi_wready and S_AXI_WVALID and axi_awready and S_AXI_AWVALID ;

	process (S_AXI_ACLK)
	variable loc_addr :std_logic_vector(OPT_MEM_ADDR_BITS downto 0); 
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      slv_reg0 <= (others => '0');
	      slv_reg1 <= (others => '0');
	      slv_reg2 <= (others => '0');
	      slv_reg3 <= (others => '0');
	      slv_reg4 <= (others => '0');
	      slv_reg5 <= (others => '0');
	      slv_reg6 <= (others => '0');
	      slv_reg7 <= (others => '0');
	      slv_reg8 <= (others => '0');
	      slv_reg9 <= (others => '0');
	      slv_reg10 <= (others => '0');
	      slv_reg11 <= (others => '0');
	      slv_reg12 <= (others => '0');
	      slv_reg13 <= (others => '0');
	      slv_reg14 <= (others => '0');
	      slv_reg15 <= (others => '0');
	      slv_reg16 <= (others => '0');
	    else
	      loc_addr := axi_awaddr(ADDR_LSB + OPT_MEM_ADDR_BITS downto ADDR_LSB);
	      if (slv_reg_wren = '1') then
	        case loc_addr is
	          when b"00000" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 0
	                slv_reg0(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"00001" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 1
	                slv_reg1(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"00010" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 2
	                slv_reg2(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"00011" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 3
	                slv_reg3(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"00100" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 4
	                slv_reg4(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"00101" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 5
	                slv_reg5(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"00110" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 6
	                slv_reg6(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"00111" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 7
	                slv_reg7(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"01000" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 8
	                slv_reg8(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"01001" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 9
	                slv_reg9(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"01010" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 10
	                slv_reg10(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"01011" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 11
	                slv_reg11(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"01100" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 12
	                slv_reg12(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"01101" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 13
	                slv_reg13(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"01110" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 14
	                slv_reg14(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"01111" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 15
	                slv_reg15(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when b"10000" =>
	            for byte_index in 0 to (C_S_AXI_DATA_WIDTH/8-1) loop
	              if ( S_AXI_WSTRB(byte_index) = '1' ) then
	                -- Respective byte enables are asserted as per write strobes                   
	                -- slave registor 16
	                slv_reg16(byte_index*8+7 downto byte_index*8) <= S_AXI_WDATA(byte_index*8+7 downto byte_index*8);
	              end if;
	            end loop;
	          when others =>
	            slv_reg0 <= slv_reg0;
	            slv_reg1 <= slv_reg1;
	            slv_reg2 <= slv_reg2;
	            slv_reg3 <= slv_reg3;
	            slv_reg4 <= slv_reg4;
	            slv_reg5 <= slv_reg5;
	            slv_reg6 <= slv_reg6;
	            slv_reg7 <= slv_reg7;
	            slv_reg8 <= slv_reg8;
	            slv_reg9 <= slv_reg9;
	            slv_reg10 <= slv_reg10;
	            slv_reg11 <= slv_reg11;
	            slv_reg12 <= slv_reg12;
	            slv_reg13 <= slv_reg13;
	            slv_reg14 <= slv_reg14;
	            slv_reg15 <= slv_reg15;
	            slv_reg16 <= slv_reg16;
	        end case;
	      end if;
	    end if;
	  end if;                   
	end process; 

	-- Implement write response logic generation
	-- The write response and response valid signals are asserted by the slave 
	-- when axi_wready, S_AXI_WVALID, axi_wready and S_AXI_WVALID are asserted.  
	-- This marks the acceptance of address and indicates the status of 
	-- write transaction.

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_bvalid  <= '0';
	      axi_bresp   <= "00"; --need to work more on the responses
	    else
	      if (axi_awready = '1' and S_AXI_AWVALID = '1' and axi_wready = '1' and S_AXI_WVALID = '1' and axi_bvalid = '0'  ) then
	        axi_bvalid <= '1';
	        axi_bresp  <= "00"; 
	      elsif (S_AXI_BREADY = '1' and axi_bvalid = '1') then   --check if bready is asserted while bvalid is high)
	        axi_bvalid <= '0';                                 -- (there is a possibility that bready is always asserted high)
	      end if;
	    end if;
	  end if;                   
	end process; 

	-- Implement axi_arready generation
	-- axi_arready is asserted for one S_AXI_ACLK clock cycle when
	-- S_AXI_ARVALID is asserted. axi_awready is 
	-- de-asserted when reset (active low) is asserted. 
	-- The read address is also latched when S_AXI_ARVALID is 
	-- asserted. axi_araddr is reset to zero on reset assertion.

	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then 
	    if S_AXI_ARESETN = '0' then
	      axi_arready <= '0';
	      axi_araddr  <= (others => '1');
	    else
	      if (axi_arready = '0' and S_AXI_ARVALID = '1') then
	        -- indicates that the slave has acceped the valid read address
	        axi_arready <= '1';
	        -- Read Address latching 
	        axi_araddr  <= S_AXI_ARADDR;           
	      else
	        axi_arready <= '0';
	      end if;
	    end if;
	  end if;                   
	end process; 

	-- Implement axi_arvalid generation
	-- axi_rvalid is asserted for one S_AXI_ACLK clock cycle when both 
	-- S_AXI_ARVALID and axi_arready are asserted. The slave registers 
	-- data are available on the axi_rdata bus at this instance. The 
	-- assertion of axi_rvalid marks the validity of read data on the 
	-- bus and axi_rresp indicates the status of read transaction.axi_rvalid 
	-- is deasserted on reset (active low). axi_rresp and axi_rdata are 
	-- cleared to zero on reset (active low).  
	process (S_AXI_ACLK)
	begin
	  if rising_edge(S_AXI_ACLK) then
	    if S_AXI_ARESETN = '0' then
	      axi_rvalid <= '0';
	      axi_rresp  <= "00";
	    else
	      if (axi_arready = '1' and S_AXI_ARVALID = '1' and axi_rvalid = '0') then
	        -- Valid read data is available at the read data bus
	        axi_rvalid <= '1';
	        axi_rresp  <= "00"; -- 'OKAY' response
	      elsif (axi_rvalid = '1' and S_AXI_RREADY = '1') then
	        -- Read data is accepted by the master
	        axi_rvalid <= '0';
	      end if;            
	    end if;
	  end if;
	end process;

	-- Implement memory mapped register select and read logic generation
	-- Slave register read enable is asserted when valid address is available
	-- and the slave is ready to accept the read address.
	slv_reg_rden <= axi_arready and S_AXI_ARVALID and (not axi_rvalid) ;

	process (slv_reg0, slv_reg1, slv_reg2, slv_reg3, slv_reg4, slv_reg5, slv_reg6, slv_reg7, slv_reg8, slv_reg9, slv_reg10, slv_reg11, slv_reg12, slv_reg13, slv_reg14, slv_reg15, slv_reg16, axi_araddr, S_AXI_ARESETN, slv_reg_rden)
	variable loc_addr :std_logic_vector(OPT_MEM_ADDR_BITS downto 0);
	begin
	    -- Address decoding for reading registers
	    loc_addr := axi_araddr(ADDR_LSB + OPT_MEM_ADDR_BITS downto ADDR_LSB);
	    case loc_addr is
	      when b"00000" =>
	        reg_data_out <= slv_reg0;
	      when b"00001" =>
	        reg_data_out <= slv_reg1;
	      when b"00010" =>
	        reg_data_out <= slv_reg2;
	      when b"00011" =>
	        reg_data_out <= slv_reg3;
	      when b"00100" =>
	        reg_data_out <= slv_reg4;
	      when b"00101" =>
	        reg_data_out <= slv_reg5;
	      when b"00110" =>
	        reg_data_out <= slv_reg6;
	      when b"00111" =>
	        reg_data_out <= slv_reg7;
	      when b"01000" =>
	        reg_data_out <= slv_reg8;
	      when b"01001" =>
	        reg_data_out <= slv_reg9;
	      when b"01010" =>
	        reg_data_out <= slv_reg10;
	      when b"01011" =>
	        reg_data_out <= slv_reg11;
	      when b"01100" =>
	        reg_data_out <= slv_reg12;
	      when b"01101" =>
	        reg_data_out <= slv_reg13;
	      when b"01110" =>
	        reg_data_out <= slv_reg14;
	      when b"01111" =>
	        reg_data_out <= slv_reg15;
	      when b"10000" =>
	        reg_data_out <= slv_reg16;
	      when others =>
	        reg_data_out  <= (others => '0');
	    end case;
	end process; 

	-- Output register or memory read data
	process( S_AXI_ACLK ) is
	begin
	  if (rising_edge (S_AXI_ACLK)) then
	    if ( S_AXI_ARESETN = '0' ) then
	      axi_rdata  <= (others => '0');
	    else
	      if (slv_reg_rden = '1') then
	        -- When there is a valid read address (S_AXI_ARVALID) with 
	        -- acceptance of read address by the slave (axi_arready), 
	        -- output the read dada 
	        -- Read address mux
	          axi_rdata <= reg_data_out;     -- register read data
	      end if;   
	    end if;
	  end if;
	end process;


	-- Add user logic here
process (s_axi_aclk)
        begin
        if rising_edge(s_axi_aclk) then
            if (rst_in = '1') then
                current_state <= idle;
                temp_res <= '0';
            else
                temp_res <= '1';
                case (current_state) is
                    when idle   =>
                        if (init_first_r = '1') then
                            temp_dc <= '0';
                            current_state <= vddon;
                            init_first_r <= '0';
                        else
                            current_state <= waitrequest;
                        end if;
                        
                    when vddon   =>
                        temp_vdd <= '0';
                        current_state <= wait1;
                        
                    when wait1   =>
                        after_state <= dispoff;
                        current_state <= transition3;
                        
                    when dispoff   =>
                        temp_spi_data <= x"AE";
                        after_state <= setclockdiv1;
                        current_state <= transition1;  
                                      
                    when setclockdiv1   =>
                        temp_spi_data <= x"D5";
                        after_state <= setclockdiv2;
                        current_state <= transition1; 
                                    
                    when setclockdiv2   =>
                        temp_spi_data <= x"80";
                        after_state <= multiplex1;
                        current_state <= transition1; 
                                     
                    when multiplex1   =>
                        temp_spi_data <= x"A8";
                        after_state <= multiplex2;
                        current_state <= transition1; 
                                      
                    when multiplex2   =>
                        temp_spi_data <= x"1F";
                        after_state <= chargepump1;
                        current_state <= transition1; 
                                     
                    when chargepump1   =>
                        temp_spi_data <= x"8D";
                        after_state <= chargepump2;
                        current_state <= transition1; 
                        
                    when chargepump2   =>
                        temp_spi_data <= x"14";
                        after_state <= precharge1;
                        current_state <= transition1;
                        
                    when precharge1   =>
                        temp_spi_data <= x"D9";
                        after_state <= precharge2;
                        current_state <= transition1;
                    
                    when precharge2   =>                                               
                        temp_spi_data <= x"FF";
                        after_state <= vcomh1;
                        current_state <= transition1;
                    
                    when vcomh1   =>
                        temp_spi_data <= x"DB";
                        after_state <= vcomh2;
                        current_state <= transition1;
                    
                    when vcomh2   =>
                        temp_spi_data <= x"40";
                        after_state <= dispcontrast1;
                        current_state <= transition1;
                    
                    when dispcontrast1   =>
                        temp_spi_data <= x"81";
                        after_state <= dispcontrast2;
                        current_state <= transition1;
                                    
                    when dispcontrast2   =>
                        temp_spi_data <= x"F1";
                        after_state <= invertdisp1;
                        current_state <= transition1;
                    
                    when invertdisp1   =>
                        temp_spi_data <= x"A0";
                        after_state <= invertdisp2;
                        current_state <= transition1;
                    
                    when invertdisp2   =>
                        temp_spi_data <= x"C0";
                        after_state <= comconfig1;
                        current_state <= transition1;
                    
                    when comconfig1   =>
                        temp_spi_data <= x"DA";
                        after_state <= comconfig2;
                        current_state <= transition1;
                    
                    when comconfig2   =>
                        temp_spi_data <= x"02";
                        after_state <= vbaton;
                        current_state <= transition1;
                    
                    when vbaton   =>
                        temp_vbat <= '0';
                        current_state <= wait3;
                    
                    when wait3   =>                            
                        after_state <= reseton;
                        current_state <= transition3;
                    
                    when reseton   =>
                        temp_res <= '0';
                        current_state <= wait2;
                    
                    when wait2   =>
                        after_state <= resetoff;
                        current_state <= transition3;
                    
                    when resetoff   =>
                        temp_res <= '1';
                        current_state <= waitrequest;
                    
                    when waitrequest   =>
                        if (display_c = '1') then
                            current_state <= cleardc;
                            after_page_state <= readregisters;
                            temp_page <= "00";
                        elsif ((clear_c = '1') or (clear_screen_i = '1')) then
                            current_state <= cleardc;
                            after_page_state <= clearscreen;
                            temp_page <= "00";  
                        else
                            current_state <= waitrequest;
                            if ((clear_screen_i = '0') and (ready = '0')) then
                                temp_spi_data <= x"AF";
                                after_state <= waitrequest;
                                current_state <= transition1;
                                temp_dc <= '0';
                                ready <= '1';
                            end if;
                        end if;
                    
                    when cleardc   =>
                        temp_dc <= '0';
                        current_state <= setpage;
                    
                    when setpage   =>
                        temp_spi_data <= x"22";
                        after_state <= pagenum;
                        current_state <= transition1;
                    
                    when pagenum   =>
                        temp_spi_data <= "000000" & temp_page;
                        after_state <= leftcolumn1;
                        current_state <= transition1;
                    
                    when leftcolumn1   =>
                        temp_spi_data <= x"00";
                        after_state <= leftcolumn2;
                        current_state <= transition1;
                    
                    when leftcolumn2   =>
                        temp_spi_data <= x"10";
                        after_state <= setdc;
                        current_state <= transition1;
                    
                    when setdc   =>
                        temp_dc <= '1';
                        current_state <= after_page_state;
                    
                    when clearscreen   =>    
                        for i in 0 to 3 loop
                            for j in 0 to 15 loop
                                current_screen (i,j) <= x"20";
                            end loop;
                        end loop;   
                        after_update_state <= waitrequest;
                        current_state <= updatescreen;        
                    
                    when readregisters   =>
                                     -- Page0
                    current_screen(0,0)<=slv_reg0(7 downto 0);
                    current_screen(0,1)<=slv_reg0(15 downto 8);
                    current_screen(0,2)<=slv_reg0(23 downto 16);
                    current_screen(0,3)<=slv_reg0(31 downto 24);  
                                                         
                    current_screen(0,4)<=slv_reg1(7 downto 0);
                    current_screen(0,5)<=slv_reg1(15 downto 8);
                    current_screen(0,6)<=slv_reg1(23 downto 16);
                    current_screen(0,7)<=slv_reg1(31 downto 24); 
                                                                                                               
                    current_screen(0,8)<=slv_reg2(7 downto 0);  
                    current_screen(0,9)<=slv_reg2(15 downto 8); 
                    current_screen(0,10)<=slv_reg2(23 downto 16); 
                    current_screen(0,11)<=slv_reg2(31 downto 24); 
                                                                       
                    current_screen(0,12)<=slv_reg3(7 downto 0); 
                    current_screen(0,13)<=slv_reg3(15 downto 8);   
                    current_screen(0,14)<=slv_reg3(23 downto 16); 
                    current_screen(0,15)<=slv_reg3(31 downto 24); 
                    --Page1            
                    current_screen(1,0)<=slv_reg4(7 downto 0);
                    current_screen(1,1)<=slv_reg4(15 downto 8);
                    current_screen(1,2)<=slv_reg4(23 downto 16);
                    current_screen(1,3)<=slv_reg4(31 downto 24); 
                                                          
                    current_screen(1,4)<=slv_reg5(7 downto 0);
                    current_screen(1,5)<=slv_reg5(15 downto 8);
                    current_screen(1,6)<=slv_reg5(23 downto 16);
                    current_screen(1,7)<=slv_reg5(31 downto 24); 
                                                                                                                
                    current_screen(1,8)<=slv_reg6(7 downto 0);  
                    current_screen(1,9)<=slv_reg6(15 downto 8); 
                    current_screen(1,10)<=slv_reg6(23 downto 16); 
                    current_screen(1,11)<=slv_reg6(31 downto 24); 
                                                                       
                    current_screen(1,12)<=slv_reg7(7 downto 0); 
                    current_screen(1,13)<=slv_reg7(15 downto 8);   
                    current_screen(1,14)<=slv_reg7(23 downto 16); 
                    current_screen(1,15)<=slv_reg7(31 downto 24);                                                        
    
                   --Page2                    
                   current_screen(2,0)<=slv_reg8(7 downto 0);
                   current_screen(2,1)<=slv_reg8(15 downto 8);
                   current_screen(2,2)<=slv_reg8(23 downto 16);
                   current_screen(2,3)<=slv_reg8(31 downto 24);  
                                                        
                   current_screen(2,4)<=slv_reg9(7 downto 0);
                   current_screen(2,5)<=slv_reg9(15 downto 8);
                   current_screen(2,6)<=slv_reg9(23 downto 16);
                   current_screen(2,7)<=slv_reg9(31 downto 24);  
                                                                                                              
                   current_screen(2,8)<=slv_reg10(7 downto 0);  
                   current_screen(2,9)<=slv_reg10(15 downto 8); 
                   current_screen(2,10)<=slv_reg10(23 downto 16); 
                   current_screen(2,11)<=slv_reg10(31 downto 24);  
                                                                     
                   current_screen(2,12)<=slv_reg11(7 downto 0); 
                   current_screen(2,13)<=slv_reg11(15 downto 8);   
                   current_screen(2,14)<=slv_reg11(23 downto 16); 
                   current_screen(2,15)<=slv_reg11(31 downto 24);  
                   --Page3                    
                   current_screen(3,0)<=slv_reg12(7 downto 0);
                   current_screen(3,1)<=slv_reg12(15 downto 8);
                   current_screen(3,2)<=slv_reg12(23 downto 16);
                   current_screen(3,3)<=slv_reg12(31 downto 24); 
                                                         
                   current_screen(3,4)<=slv_reg13(7 downto 0);
                   current_screen(3,5)<=slv_reg13(15 downto 8);
                   current_screen(3,6)<=slv_reg13(23 downto 16);
                   current_screen(3,7)<=slv_reg13(31 downto 24); 
                                                                                                               
                   current_screen(3,8)<=slv_reg14(7 downto 0);  
                   current_screen(3,9)<=slv_reg14(15 downto 8); 
                   current_screen(3,10)<=slv_reg14(23 downto 16); 
                   current_screen(3,11)<=slv_reg14(31 downto 24);  
                                                                     
                   current_screen(3,12)<=slv_reg15(7 downto 0); 
                   current_screen(3,13)<=slv_reg15(15 downto 8);   
                   current_screen(3,14)<=slv_reg15(23 downto 16); 
                   current_screen(3,15)<=slv_reg15(31 downto 24);
                                          
                        after_update_state <= waitrequest;
                        current_state <= updatescreen;   
                   
                    when updatescreen   =>
                        temp_char <= current_screen (CONV_INTEGER(temp_page),CONV_INTEGER(temp_index));
                        
                        if ((temp_index) = "1111") then
                            temp_index <= "0000";
                            temp_page <= temp_page + 1;
                            after_char_state <= cleardc;
                            
                            if (temp_page = "11") then
                                after_page_state <= after_update_state;
                                clear_screen_i <= '0';
                            else
                                after_page_state <= updatescreen;
                            end if;
                            
                        else
                            temp_index <= temp_index + 1;
                            after_char_state <= updatescreen;                       
                        end if;
                        
                        current_state <= sendchar1; 
                    
                    when sendchar1   =>
                        temp_addr <= temp_char & "000";
                        after_state <= sendchar2;
                        current_state <= readmem; 
                    
                    when sendchar2   =>
                        temp_addr <= temp_char & "001";
                        after_state <= sendchar3;
                        current_state <= readmem; 
                                    
                    when sendchar3   =>
                        temp_addr <= temp_char & "010";
                        after_state <= sendchar4;
                        current_state <= readmem; 
                                   
                    when sendchar4   =>
                        temp_addr <= temp_char & "011";
                        after_state <= sendchar5;
                        current_state <= readmem; 
                                    
                    when sendchar5   =>
                        temp_addr <= temp_char & "100";
                        after_state <= sendchar6;
                        current_state <= readmem; 
                                    
                    when sendchar6   =>
                        temp_addr <= temp_char & "101";
                        after_state <= sendchar7;
                        current_state <= readmem; 
                                    
                    when sendchar7   =>
                        temp_addr <= temp_char & "110";
                        after_state <= sendchar8;
                        current_state <= readmem; 
                                   
                    when sendchar8   =>
                        temp_addr <= temp_char & "111";
                        after_state <= after_char_state;
                        current_state <= readmem;
                                   
                    when readmem   =>  
                        current_state <= readmem2;             
                    
                    when readmem2   =>
                        temp_spi_data <= temp_dout;
                        current_state <= transition1;
                    
                    when transition1   =>
                        temp_spi_en <= '1';
                        current_state <= transition2;
                                    
                    when transition2   =>
                        if (temp_spi_fin = '1') then
                            current_state <= transition5;
                        end if;
                    
                    when transition3   =>
                        temp_delay_en <= '1';
                        current_state <= transition4;
                    
                    when transition4   =>
                        if (temp_delay_fin = '1') then
                            current_state <= transition5;
                        end if;
                    
                    when transition5   =>
                        temp_spi_en <= '0';
                        temp_delay_en <= '0';
                        current_state <= after_state;
                        
                   when others  =>
                    current_state <= idle;
                end case;
            end if;
         end if;   
        end process;
        
        process(S_AXI_ACLK)
        begin
        if rising_edge(s_axi_aclk) then
            if (rst_in = '1') then
                count <= count + 1;
                if (count = x"FFF") then
                    rst_internal <= '0';    
                end if;
            end if;
        end if;
        end process;
	-- User logic ends

end arch_imp;
