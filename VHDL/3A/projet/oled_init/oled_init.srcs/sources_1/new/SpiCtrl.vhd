----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.11.2018 12:10:43
-- Design Name: 
-- Module Name: SpiCtrl - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity SpiCtrl is
    Port ( clk : in STD_LOGIC;
           RST : in STD_LOGIC;
           SPI_EN : in STD_LOGIC;
           SPI_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           S_CLK : out STD_LOGIC;
           SDO : out STD_LOGIC;
           SPI_FIN : out STD_LOGIC);
end SpiCtrl;

architecture Behavioral of SpiCtrl is

begin


end Behavioral;
