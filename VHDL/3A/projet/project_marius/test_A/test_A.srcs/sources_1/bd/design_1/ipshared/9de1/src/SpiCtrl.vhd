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
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity SpiCtrl is
    Port ( 
            clk : in STD_LOGIC;
           RST : in STD_LOGIC;
           SPI_EN : in STD_LOGIC;
           SPI_DATA : in STD_LOGIC_VECTOR (7 downto 0);
           S_CLK : out STD_LOGIC;
           SDO : out STD_LOGIC;
           SPI_FIN : out STD_LOGIC);
end SpiCtrl;

architecture Behavioral of SpiCtrl is
type etat_type is(idle , send, done);
signal etat : etat_type := idle;
signal count : std_logic_vector(4 downto 0);
signal shift_count : std_logic_vector(3 downto 0);
signal q1, q2 , falling: std_logic;
signal registre : std_logic_vector(7 downto 0);
begin

    process(clk)
    begin
        if rising_edge(clk) then 
            if rst='1' then
                count <= "11111";
            elsif (etat = send) then
                count <= count -1 ;
            else    
                count<="11111";
  
            end if;
        end if;  
     end process;
         
     S_CLK <= count(4);
     
     process (clk)
     
    begin
        if rising_edge(clk) then 
            if rst='1' then
                q1 <= '0';
                q2 <= '0';
            else    
                q1 <= count(4);
                q2 <= q1 ;

            end if;
        end if;  
     end process;
     
     falling <= q2 and not q1;
     
     process(clk)
     begin
         if rising_edge(clk) then
             if RST='1' then
                 etat<=idle;
             else
                 case etat is
                     when idle =>
                        registre <= SPI_DATA;
                        shift_count <="0000";
                        spi_fin<='0';
                        if spi_en ='1' then
                         etat <= send;
                        end if;
                     when send =>
                         spi_fin<='0';
                         if (falling='1') then
                            SDO <= registre(7); 
                            registre <= registre(6 downto 0) & '0';
                            shift_count <= shift_count + 1;
                          end if;

                             if (shift_count="1000" and count ="11000") then
                                etat <= done;
                         end if; 
                     when done => 
                     spi_fin<='1';
                     if (spi_en='0') then
                         etat <= idle;
                     end if;
                      
                 end case;
                     
             end if; 
         end if;
     end process;
    
end Behavioral;
