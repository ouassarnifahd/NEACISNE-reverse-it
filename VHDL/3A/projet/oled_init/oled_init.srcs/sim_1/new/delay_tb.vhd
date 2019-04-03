----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.11.2018 11:24:33
-- Design Name: 
-- Module Name: delay_tb - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity delay_tb is
--  Port ( );
end delay_tb;

architecture Behavioral of delay_tb is

component delay is
    Port ( clk : in STD_LOGIC;
           RST : in STD_LOGIC;
           DELAY_EN : in STD_LOGIC;
           DELAY_MS : in STD_LOGIC_VECTOR (11 downto 0);
           DELAY_FIN : out STD_LOGIC);
end component;

    signal clk,RST,DELAY_EN,DELAY_FIN :std_logic;
     signal DELAY_MS :std_logic_vector(11 downto 0);
begin

DUT : delay port map (

    -- composant => fil
    clk => clk,
    RST => RST,
    DELAY_EN => DELAY_EN,
    DELAY_FIN => DELAY_FIN,
    DELAY_MS => DELAY_MS
);

process 
begin
    clk <='1';
    wait for 5 ns;
    clk <= '0';
    wait for 5 ns;
end process;

process 
begin
    DELAY_MS <= "000000000011";
    RST <= '1';
    DELAY_EN <= '0';
    wait for 100 ns;
    RST <= '0';
    wait for 100 ns;
    DELAY_EN <= '1';
    wait for 5 ms;
    DELAY_EN <= '0';
    wait ;
end process;

end Behavioral;
